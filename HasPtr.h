/*c++ pointer:
   1.plain pointer
   2.smart pointer
   3.class manage pointers,pointer is assigned by value
*/
//class that has a pointer member that behaves like a plain pointer
using namespace std;
class HasPtr{
public:
    //copy of the values we're given
    HasPtr(int *p,int i):ptr(p),val(i){}
    HasPtr(const HasPtr &orig):ptr(new int(*orig.ptr)),val(orig.val){}
    HasPtr& operator=(const HasPtr&);
    //const members to return the value of the indicated data member
    int *get_ptr() const {return ptr;}
    int get_int() const {return val;}
    //non const members to change the indicated data member
    void set_ptr(int *p)  {ptr = p;}
    void set_int(int i) {val = i;}
    //return or change the value that ptr pointed to,so ok for const objects
    int get_ptr_val() const {return *ptr;}
    void set_ptr_val(int val) const {*ptr = val;}
private:
    int *ptr;
    int val;
};
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    *ptr=*rhs.ptr;
    val=rhs.val;
    return *this;
}
