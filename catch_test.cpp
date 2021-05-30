#include <string>
#include <iostream>
using namespace std;
void manip()
{
    try{
        //actions that cause an exception to be thrown
    }
    catch(...)//...catch all exception
    {
        //work to partially handle the exception
    }
}
template<class T> class Handle
{
    Handle(T*);
};
//可以捕捉初始化列表异常以及函数体内的异常
template<class T> Handle<T>::Handle(T *p)
try:ptr(p),use(new size_t(1))
{
    //empty function body
}catch(const std::bad_alloc &e)
{
    handle_out_of_memoryle;
}
class out_of_stock:public std::runtime_error{
public:
    explicit out_of_stock(const std::string &s):std::runtime_error(s){}
};
