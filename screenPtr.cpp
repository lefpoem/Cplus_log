#include "Screen.h"
class ScrPtr
{
    friend class ScreenPtr;
    Screen *sp;
    size_t use;
    ScrPtr(Screen *p):sp(p),use(1){}
    ~ScrPtr() {delete sp;}
};
/*smart pointer : Users pass to a pointer to a dynamically allocated
Screen,which is automatically destroyed when the last ScreenPtr goes
away
*/
class ScreenPtr
{
public:
    //no default constructor:ScreenPtrs must be bound to an object
    ScreenPtr(Screen *p):ptr(new ScrPtr(p)) {}
    //copy members and increment the use count
    ScreenPtr(const ScreenPtr &orig): ptr(orig.ptr){++ptr->use;}
    ScreenPtr& operator=(const ScreenPtr&);
    //if use count goes to zero,delete the ScrPtr object
    ~ScreenPtr() {if(--ptr->use==0) delete ptr;}
    Screen& operator*(){return *ptr->sp;}
    Screen* operator->() {return ptr->sp;}
private:
    ScrPtr *ptr;
};
ScreenPtr p1;//error:ScreenPtr has  no default constructor