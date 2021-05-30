#include <string>
#include <queue>
using namespace std;
//nontemplate class friend
template<class Type> class Bar{
    //grants access to ordinary,nontemplate and fuction
    friend class FooBar;
    friend void fcn();
};
//ordinary template class
template<class Type> class Bas{
    //grants access to Fool or temp1_fcn1 parameterized by any type
    template<class T> friend class Fool;
    template<class T> friend void temp1_fcn1(const T&);
};
//instantiated template class and fuction friend
template<class T> class Foo2;
template<class T> void temp1_fcn2(const T&);
template<class Type> class Queue
{
   template<class It> void copy_elems(It,It);
};
template<class Type> class Bat
{
    friend class Foo2<char*>;
    friend void temp1_fcn2<char*>(char* const&);
};
template<class Type> template<class It>//template class member
void Queue<Type>::copy_elems(It beg,It end)
{
    while (beg!=end)
    {
        push(*beg);
        ++beg;
    }
    
}
template<class T> int compare(const T& t1,const T& t2){}
//declaration of function template explicit specialization
//特化调用之前必须声明
template<> int compare<const char*>(const char* const&,const char* const &);
template<> int compare(const char* const&,const char* const&);
template<> class Queue<const char*>{
public:
    //no copy control:Synthesized versions work for this class
    //similarly,no need for explicit default constructor either
    void push(const char*);
    void pop(){real_queue.pop();}
    bool empty() const {return real_queue.empty();}
    const string &front() const {return real_queue.front();}
private:
    queue<string> real_queue;
};
void Queue<const char*>::push(const char* val)
{
    return real_queue.push(val);
}
template<class T1,class T2>
class some_template{};
//partial specialization: fixes T2 as int and allows T1 to vary
template<class T1> class some_template<T1,int>{};