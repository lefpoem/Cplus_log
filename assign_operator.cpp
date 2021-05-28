/*当操作符为成员函数时，第一个操作数隐式绑定到this指针
*赋值操作符定义为成员函数，算术，相等，关系，位，定义为非成员函数*/
//equivalent to the synthesized assignment operator
#include "Sales_item.h"
Sales_item& Sales_item :: operator=(const Sales_item &rhs)
{
    isbn = rhs.isbn;
    unites_sold = rhs.unites_sold;
    revenue = rhs.revenue;
    return *this;
}
