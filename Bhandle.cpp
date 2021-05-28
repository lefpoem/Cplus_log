#include "Sales_item.h"
#include <set>
class Basket{
    //type of the comparison function used to order the multiset
    typedef bool (*Comp)(const Sales_item&,const Sales_item&);
public:
    //make it easier to the type of our see
    typedef std::multiset<Sales_item,Comp> set_type;
    //typedefs modeled after corresponding container types
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;
    Basket(): items(compare){}//initialize the comparator
    void add_item(const Sales_item &item){items.insert(item);}
    size_type size(const Sales_item& i){return items.count(i);}
    double total() const;//sum of net prices for all items in the basket
private:
    std::multiset<Sales_item,Comp> items;
};
inline bool compare(const Sales_item& lhs,const Sales_item& rhs)
{
    return lhs.book() < rhs.book();
}
double Basket::total() const{
    double sum=0.0;//holds the running total
    for(const_iter iter = items.begin();iter!=items.end();iter=items.upper_bound(*iter))
    {}
}
