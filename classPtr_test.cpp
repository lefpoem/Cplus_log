#include <iostream>
#include "HasPtr.h"
using namespace std;
#define size 10
int ia[size];
int main()
{
    int obj = 0;
    HasPtr ptr1(&obj,42);//int* member points to obj,val is 42;
    HasPtr ptr2(ptr1);//int* member points to obj,val is 42;
    //all pointer indicated the same object
    ptr1.set_int(0);//change val number only in ptr1
    ptr2.get_int(); //returns 42
    ptr1.get_int(); //returns 0
    ptr1.set_ptr_val(42);//sets objects to which both ptr1 and ptr2
    ptr2.get_ptr_val(); //returns *ptr,return 42
    cout << ptr2.get_ptr_val() << endl;
    int *ip=new int(42);//dynamically allocated int initialized to 42
    HasPtr ptr(ip,10);//HasPtr points to same objects as ip does
    delete ip;//object pointed by ip is freed
    ptr.set_ptr_val(0);//The object to which HasPtr points was freed!
    CheckedPtr parr(ia,ia+size);//ia points to an array of ints
    parr.operator++(0);//call postfix operator++
    parr.operator++();//call prefix operator--
    return 0;
}
class CheckedPtr
{
public:
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    CheckedPtr& operator--(int);
    CheckedPtr& operator++(int);
    CheckedPtr(int *b,int *c):beg(b),end(c),curr(b){}
private:
    int* beg;
    int* end;
    int* curr;
};
CheckedPtr& CheckedPtr::operator++()//prefix
{
    if(curr==end)
        throw out_of_range("increment past of the end of CheckedPtr");
    ++curr;  //advance current state
    return *this;
}
CheckedPtr& CheckedPtr::operator--()//prefix
{
    if(curr==beg)
        throw out_of_range("decrement past of the beginning of CheckedPtr");
    --curr; //move current state back one element
    return *this;
}
CheckedPtr& CheckedPtr::operator++(int)
{
    //no check needed here,the call to prefix increment will do the check
    CheckedPtr ret(*this); // save current value
    ++*this; //advance one element,checking the increment
    return ret;//return save state
}
CheckedPtr& CheckedPtr::operator--(int)
{
    CheckedPtr ret(*this);//save current value
    --*this;//advance one element
    return ret;//return save state
}
