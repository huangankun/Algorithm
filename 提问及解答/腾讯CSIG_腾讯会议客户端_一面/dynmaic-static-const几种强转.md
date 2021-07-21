###[static_pointer_cast、dynamic_pointer_cast、const_pointer_cast、reinterpret_pointer_cast](https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast)
1. Creates a new instance of std::shared_ptr whose stored pointer is obtained from r's stored pointer using a cast expression.

2. If r is empty, so is the new shared_ptr (but its stored pointer is not necessarily null). Otherwise, the new shared_ptr will share ownership with the initial value of r, except that it is empty if the dynamic_cast performed by dynamic_pointer_cast returns a null pointer.

3. Let Y be typename std::shared_ptr<T>::element_type, then the resulting std::shared_ptr's stored pointer will be obtained by evaluating, respectively:

``` 
1-2) static_cast<Y*>(r.get()).
3-4) dynamic_cast<Y*>(r.get()) (If the result of the dynamic_cast is a null pointer value, the returned shared_ptr will be empty.)
5-6) const_cast<Y*>(r.get()).
7-8) reinterpret_cast<Y*>(r.get())
```
The behavior of these functions is undefined unless the corresponding cast from U* to T* is well formed:

```
1-2) The behavior is undefined unless static_cast<T*>((U*)nullptr) is well formed.
3-4) The behavior is undefined unless dynamic_cast<T*>((U*)nullptr) is well formed.
5-6) The behavior is undefined unless const_cast<T*>((U*)nullptr) is well formed.
7-8) The behavior is undefined unless reinterpret_cast<T*>((U*)nullptr) is well formed.
```

###Note
4. The expressions std::shared_ptr<T>(static_cast<T*>(r.get())), std::shared_ptr<T>(dynamic_cast<T*>(r.get())) and std::shared_ptr<T>(const_cast<T*>(r.get())) might seem to have the same effect, but they all will likely result in undefined behavior, attempting to delete the same object twice!

###Example
```c++
#include <iostream>
#include <memory>
 
struct Base 
{ 
    int a; 
    virtual void f() const { std::cout << "I am base!\n";}
    virtual ~Base(){}
};
 
struct Derived : Base
{
    void f() const override
    { std::cout << "I am derived!\n"; }
    ~Derived(){}
};
 
int main(){
    auto basePtr = std::make_shared<Base>();
    std::cout << "Base pointer says: ";
    basePtr->f();
 
    auto derivedPtr = std::make_shared<Derived>();
    std::cout << "Derived pointer says: ";
    derivedPtr->f();
 
    // static_pointer_cast to go up class hierarchy
    basePtr = std::static_pointer_cast<Base>(derivedPtr);
    std::cout << "Base pointer to derived says: ";
    basePtr->f();
 
    // dynamic_pointer_cast to go down/across class hierarchy
    auto downcastedPtr = std::dynamic_pointer_cast<Derived>(basePtr);
    if(downcastedPtr)
    { 
        std::cout << "Downcasted pointer says: ";
        downcastedPtr->f(); 
    }
 
    // All pointers to derived share ownership
    std::cout << "Pointers to underlying derived: " 
            << derivedPtr.use_count() 
            << "\n"; 
}
```

###Output
```
Base pointer says: I am base!
Derived pointer says: I am derived!
Base pointer to derived says: I am derived!
Downcasted pointer says: I am derived!
Pointers to underlying derived: 3
```