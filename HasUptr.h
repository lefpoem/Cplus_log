#include "U_Ptr.h"
class HasUptr
{
public:
    //HasUptr owns the pointer:p must haver been dynamically allocated
    HasUptr(int *p,int i):ptr(new U_Ptr(p)),val(i){}
    //copy members and increment the use count
    HasUptr(const HasUptr &orig):ptr(orig.ptr),val(orig.val){++ptr->use;}
    HasUptr &operator=(const HasUptr&);
    //if use count goes to zero,delete the U_Ptr object
    ~HasUptr() {if(--ptr->use == 0)delete ptr;}
private:
    U_Ptr *ptr;//points to use-counted U_Ptr class
    int val;
};
HasUptr& HasUptr::operator=(const HasUptr &rhs)
{
    ++rhs.ptr->use; //increment use count on rhs first
    if(--ptr->use==0)
       delete ptr;
    ptr=rhs.ptr;
    val=rhs.val;
    return *this;
}
