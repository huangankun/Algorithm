### std::enable_shared_from_this
```
定义于头文件 <memory>
template< class T > class enable_shared_from_this;
```
### 解释
1. std::enable_shared_from_this 能让其一个对象（假设其名为 t ，且已被一个 std::shared_ptr 对象 pt 管理）安全地生成其他额外的 std::shared_ptr 实例（假设名为 pt1, pt2, ... ） ，它们与 pt 共享对象 t 的所有权。

2. 若一个类 T 继承 std::enable_shared_from_this<T> ，则会为该类 T 提供成员函数： shared_from_this 。 当 T 类型对象 t 被一个为名为 pt 的 std::shared_ptr<T> 类对象管理时，调用 T::shared_from_this 成员函数，将会返回一个新的 std::shared_ptr<T> 对象，它与 pt 共享 t 的所有权。

|  成员函数   |   |
|  ----  | ----  |
| 构造函数  | 构造 enable_shared_from_this 对象(受保护成员函数) |
| 析构函数  | 销毁 enable_shared_from_this 对象(受保护成员函数) |
| operator=|返回到 this 的引用(受保护成员函数)|
|shared_from_this|返回共享 *this 所有权的 shared_ptr(公开成员函数)|
|weak_from_this(C++17)|返回共享 *this 所有权的 weak_ptr(公开成员函数)|

###成员对象
3. weak_this (私有成员对象)(C++17)	追踪 *this 的首个共享占有者的控制块的 std::weak_ptr 对象。仅为说明。

###注意
4. enable_shared_from_this 的常见实现为：其内部保存着一个对 this 的弱引用（例如 std::weak_ptr )。 std::shared_ptr 的构造函数检测无歧义且可访问的 (C++17 起) enable_shared_from_this 基类，并且若内部存储的弱引用未为生存的 std::shared_ptr 占有，则 (C++17 起)赋值新建的 std::shared_ptr 为内部存储的弱引用。为已为另一 std::shared_ptr 所管理的对象构造一个 std::shared_ptr ，将不会考虑内部存储的弱引用，从而将导致未定义行为。只允许在先前已被std::shared_ptr 管理的对象上调用 shared_from_this 。否则调用行为未定义 (C++17 前)抛出 std::bad_weak_ptr 异常（通过 shared_ptr 从默认构造的 weak_this 的构造函数） (C++17 起)。enable_shared_from_this 提供安全的替用方案，以替代 std::shared_ptr<T>(this) 这样的表达式（这种不安全的表达式可能会导致 this 被多个互不知晓的所有者析构，见下方示例）。

###代码
```c++
#include <memory>
#include <iostream>
 
struct Good: std::enable_shared_from_this<Good> // 注意：继承
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};
 
struct Bad
{
    // 错误写法：用不安全的表达式试图获得 this 的 shared_ptr 对象
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};
 
int main()
{
    // 正确的示例：两个 shared_ptr 对象将会共享同一对象
    std::shared_ptr<Good> gp1 = std::make_shared<Good>();
    std::shared_ptr<Good> gp2 = gp1->getptr();
    std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';
 
    // 错误的使用示例：调用 shared_from_this 但其没有被 std::shared_ptr 占有
    try {
        Good not_so_good;
        std::shared_ptr<Good> gp1 = not_so_good.getptr();
    } catch(std::bad_weak_ptr& e) {
        // C++17 前为未定义行为； C++17 起抛出 std::bad_weak_ptr 异常
        std::cout << e.what() << '\n';    
    }
 
    // 错误的示例，每个 shared_ptr 都认为自己是对象仅有的所有者
    std::shared_ptr<Bad> bp1 = std::make_shared<Bad>();
    std::shared_ptr<Bad> bp2 = bp1->getptr();
    std::cout << "bp2.use_count() = " << bp2.use_count() << '\n';
} // UB ： Bad 对象将会被删除两次
```
###输出
```
gp2.use_count() = 2
bad_weak_ptr
bp2.use_count() = 1
Bad::~Bad() called
Bad::~Bad() called
*** glibc detected *** ./test: double free or corruption
```
