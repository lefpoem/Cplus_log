#include <cstdlib>
#include <memory>
using namespace std;
//presudo-implement of memory allocation strategy for a vector-like class
template<class T> class Vector{
public:
    Vector():elements(0),first_free(0),end(0){}
    void push_back(const T&);
    //....
private:
    static std::allocator<T> alloc;//object to get raw memory
    void reallocate();//get more space and copy existing elements
    T* element;//pointer to first element in the array
    T* first_free;//pointer to first free element in the array
    T* end;//pointer to one past the end of the array
};
template<class T> void Vector<T>::push_back(const T& t)
{
    if(first_free==end)
        reallocate();//gets more space and copies existing elements
    alloc.construct(first_free,t);
    ++first_free;
}
template<class T> void Vector<T>::reallocate()
{
    ptrdiff_t size=first_free-element;
    ptrdiff_t newcapacity=2*max(size,1);
    T* newelements=alloc.allocate(newcapacity);
    //consruct copies of the existing elements in the new space
    uninitialized_copy(element,first_free,newelements);
    //destroy the old elements in reverse order
    for(T* p =first_free;p!=element;--p)
        alloc.destroy(--p);
    //deallocate cannot be called on a 0 pointer
    if(element)
        //return the memory that held the element
        alloc.deallocate(element,end_element);
    //make our data structure point to the new elements
    element =newelements;
    first_free=element+size;
    end = element+newcapacity;
}
//locate new;new(first-free) t(T);
/*memory allocation class:Pre-allocates objects and maintain freelist of
object that are unused when an object is freed ,it is put back on the
freelist.The memory is only the returned when the program exits*/
template<class T> class CacheObj{//只能用于不做基类使用的类
public:
    void* operator new(size_t);
    void operator delete(void*,size_t);
    virtual ~CacheObj();
protected:
    T* next;
private:
    static void add_to_freelist(T*);
    static allocator<T> alloc_mem;
    static T* freestore;//the head of freelist
    static const size_t chunk;
};
class Screen: public CacheObj<Screen>{};
template<class Type> class QueueItem: public CacheObj<QueueItem>{};
template<class T>
void CacheObj<T>::operator delete(void *p,size_t i)
{
    if(p!=0)
        //put the "deleted" object back at head of freelist
        add_to_freelist(static_cast<T*>(p));
}
