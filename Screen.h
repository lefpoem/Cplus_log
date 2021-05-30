#ifndef SCREEN
#define SCREEN
#include <string>
using namespace std;
int height;
class Screen{
public:
     //interface member function
     friend class Window_Mgr;
     typedef string::size_type index;
     char get() const{return contents[cursor];}
     inline char get(index ht,index width) const;
     index get_cursor() const;
     Screen& move(index r,index c);
     Screen& set(char);
     Screen& set(index,index,char);
     void do_display(ostream&) const;
     Screen& clear(char = bkground);//static member used to default parameter
     void dummy_fcn(index height)
     {
         cursor = width*this->height;//member height
         //alternative way to indicate the member
         cursor =width*Screen::height;//member height
         cursor =width*height;//parameter height
         cursor =width*::height;//global height
     }
private:
    string contents;
    index cursor;
    index height,width;
    static const char bkground = '#';
    mutable size_t access_ctr;//may change in a const member
};
inline char Screen::get(index r,index c) const
{
    index row = r*width;
    return contents[row+c];
}
inline Screen::index Screen::get_cursor() const
{
    return cursor;
}
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen& Screen::move(index r,index c)
{
    index row = r*width;
    cursor = row +c;
    return *this;
}
void Screen::do_display(ostream& os) const
{
    ++access_ctr; //keep cunnt of calls  to any member function
    os << contents;
}
#endif