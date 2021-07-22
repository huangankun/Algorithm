###[shared_ptr](https://zh.cppreference.com/w/cpp/memory/shared_ptr)
1. 定义于头文件 <memory>
2. template< class T > class shared_ptr;(C++11 起)
3. std::shared_ptr 是通过指针保持对象共享所有权的智能指针。多个 shared_ptr 对象可占有同一对象。下列情况之一出现时销毁对象并解分配其内存：
```
    最后剩下的占有对象的 shared_ptr 被销毁；
    最后剩下的占有对象的 shared_ptr 被通过 operator= 或 reset() 赋值为另一指针。
```
4. 用 delete 表达式或在构造期间提供给 shared_ptr 的定制删除器销毁对象。

5. shared_ptr 能在存储指向一个对象的指针时共享另一对象的所有权。此特性能用于在占有其所属对象时，指向成员对象。存储的指针为 get() 、解引用及比较运算符所访问。被管理指针是在 use_count 抵达零时传递给删除器者。
6. shared_ptr 亦可不占有对象，该情况下称它为空 (empty) （空 shared_ptr 可拥有非空存储指针，若以别名使用构造函数创建它）。
7. shared_ptr 的所有特化满足可复制构造 (CopyConstructible) 、可复制赋值 (CopyAssignable) 和可小于比较 (LessThanComparable) 的要求并可按语境转换为 bool 。
8. 多个线程能在 shared_ptr 的不同实例上调用所有成员函数（包含复制构造函数与复制赋值）而不附加同步，即使这些实例是副本，且共享同一对象的所有权。若多个执行线程访问同一 shared_ptr 而不同步，且任一线程使用 shared_ptr 的非 const 成员函数，则将出现数据竞争；原子函数的 shared_ptr 特化能用于避免数据竞争。

###注意
9. 只能通过复制构造或复制赋值其值给另一 shared_ptr ，将对象所有权与另一 shared_ptr 共享。用另一 shared_ptr 所占有的底层指针创建新的 shared_ptr 导致未定义行为。

10. std::shared_ptr 可以用于不完整类型 T 。然而，参数为裸指针的构造函数（ template<class Y> shared_ptr(Y*) ）和 template<class Y> void reset(Y*) 成员函数只可以用指向完整类型的指针调用（注意 std::unique_ptr 可以从指向不完整类型的裸指针构造）。

###实现说明
11. 在典型的实现中， std::shared_ptr 只保有二个指针：
```
    1   get() 所返回的指针
    2   指向控制块的指针
```
12. 控制块是一个动态分配的对象，其中包含：
```
    1   指向被管理对象的指针或被管理对象本身
    2   删除器（类型擦除）
    3   分配器（类型擦除）
    4   占有被管理对象的 shared_ptr 的数量
    5   涉及被管理对象的 weak_ptr 的数量
```
13. 以调用 std::make_shared 或 std::allocate_shared 创建 shared_ptr 时，以单次分配创建控制块和被管理对象。被管理对象在控制块的数据成员中原位构造。通过 shared_ptr 构造函数之一创建 shared_ptr 时，被管理对象和控制块必须分离分配。此情况中，控制块存储指向被管理对象的指针。

14. shared_ptr 持有的指针是通过 get() 返回的；而控制块所持有的指针/对象则是最终引用计数归零时会被删除的那个。两者并不一定相等。

15. shared_ptr 的析构函数会将控制块中的 shared_ptr 计数器减一，如果减至零，控制块就会调用被管理对象的析构函数。但控制块本身直到 std::weak_ptr 计数器同样归零时才会释放。

16. 既存实现中，若有共享指针指向同一控制块，则自增弱指针计数 ([1], [2]) 。

17. 为满足线程安全要求，引用计数器典型地用等价于用 std::memory_order_relaxed 的 std::atomic::fetch_add 自增（自减要求更强的顺序，以安全销毁控制块）。

###示例
运行此代码
```c++
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
 
struct Base
{
    Base() { std::cout << "  Base::Base()\n"; }
    // 注意：此处非虚析构函数 OK
    ~Base() { std::cout << "  Base::~Base()\n"; }
};
 
struct Derived: public Base
{
    Derived() { std::cout << "  Derived::Derived()\n"; }
    ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};
 
void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // 线程安全，虽然自增共享的 use_count
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}
 
int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';
    std::thread t1(thr, p), t2(thr, p), t3(thr, p);
    p.reset(); // 从 main 释放所有权
    std::cout << "Shared ownership between 3 threads and released\n"
              << "ownership from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';
    t1.join(); t2.join(); t3.join();
    std::cout << "All threads completed, the last one deleted Derived\n";
}
```
可能的输出：
```
Base::Base()
  Derived::Derived()
Created a shared Derived (as a pointer to Base)
  p.get() = 0x2299b30, p.use_count() = 1
Shared ownership between 3 threads and released
ownership from main:
  p.get() = 0, p.use_count() = 0
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 5
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 3
local pointer in a thread:
  lp.get() = 0x2299b30, lp.use_count() = 2
  Derived::~Derived()
  Base::~Base()
All threads completed, the last one deleted Derived
```