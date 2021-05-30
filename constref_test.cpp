#include "Sales_item.h"
//c++ has:Sales_item item1;
//inherited by c:class Sales_item item1;
class ConstRef
{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int& ri;
};
//reference need initialization
ConstRef::ConstRef(int ii):i(ii),ci(i),ri(i)
{
    ri=ii;
}
