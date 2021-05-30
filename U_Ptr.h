#include <iostream>
using namespace std;
//private class for use by HasPtr only
//class U_Ptr belongs to class Has_Ptr
class U_Ptr{
    friend class HasUptr;
    int *ip;
    size_t use;
    U_Ptr(int *p):ip(p),use(1){}
    ~U_Ptr() {delete ip;}
};