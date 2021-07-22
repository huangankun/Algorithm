###[weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr)

1. std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr. It must be converted to std::shared_ptr in order to access the referenced object.

2. std::weak_ptr models temporary ownership: when an object needs to be accessed only if it exists, and it may be deleted at any time by someone else, std::weak_ptr is used to track the object, and it is converted to std::shared_ptr to assume temporary ownership. If the original std::shared_ptr is destroyed at this time, the object's lifetime is extended until the temporary std::shared_ptr is destroyed as well.

3. Another use for std::weak_ptr is to break reference cycles formed by objects managed by std::shared_ptr. If such cycle is orphaned (i,e. there are no outside shared pointers into the cycle), the shared_ptr reference counts cannot reach zero and the memory is leaked. To prevent this, one of the pointers in the cycle can be made weak.

|Member functions||
|-----|-----|
|constructor|creates a new weak_ptr|
|destructor|destroys a weak_ptr|
|operator=|assigns the weak_ptr|
|use_count|returns the number of shared_ptr objects that manage the object|
|expired|	checks whether the referenced object was already deleted|
|lock|creates a shared_ptr that manages the referenced object|

###Notes
4. Like std::shared_ptr, a typical implementation of weak_ptr stores two pointers:
```
a pointer to the control block; and
the stored pointer of the shared_ptr it was constructed from.
```
5. A separate stored pointer is necessary to ensure that converting a shared_ptr to weak_ptr and then back works correctly, even for aliased shared_ptrs. It is not possible to access the stored pointer in a weak_ptr without locking it into a shared_ptr.

###Example

```C++
#include <iostream>
#include <memory>
 
std::weak_ptr<int> gw;
 
void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
	std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}
 
int main()
{
    {
        auto sp = std::make_shared<int>(42);
	gw = sp;
 
	observe();
    }
 
    observe();
}
```

###Output
```
use_count == 1: 42
use_count == 0: gw is expired
```
