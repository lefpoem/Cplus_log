#include <iostream>
#include <string>
using namespace std;
class Sales_item{
    friend Sales_item& operator+(Sales_item& amo,Sales_item& rhs);
public:
    friend istream& operator>>(istream &,Sales_item&);
    //operation on Sale_item object
    double avg_price() const;
    Sales_item& book() const {}
    bool same_isbn (const Sales_item &rhs) const{
        return isbn == rhs.isbn;
    }
    Sales_item& Sales_item :: operator=(const Sales_item &rhs)
    {
        isbn = rhs.isbn;
        unites_sold = rhs.unites_sold;
        revenue = rhs.revenue;
        return *this;
    }
    Sales_item(const std::string&);//explict can stop it will generate a implicit conversion
    Sales_item(std::istream&);
    Sales_item();//constructor don't allow to use type declaration
    //error:Sales_item() const;
    ~Sales_item(){}//destructor
private:
    std::string isbn;
    unsigned unites_sold;
    double revenue;
};
//初始化列表中初始化，函数体对其cover,初始化列表只在定义中而不是声明中指定
Sales_item::Sales_item(const std::string& book):isbn(book),unites_sold(0),revenue(0.0)
{
    isbn = book;
    unites_sold= 5;
    revenue = 0.0;
}
istream& operator>>(istream &in,Sales_item &s)
{
    double price;
    in >> s.isbn ;
    //check that the inputs succeeded
    if(in)
       s.revenue = s.unites_sold*price;
    else 
       s = Sales_item();//input failed:reset object to defualt state
    return in;
}
Sales_item& operator+(Sales_item& amo,Sales_item& rhs){
        amo.isbn = rhs.isbn + amo.isbn;
}
bool operator<(Sales_item& amo,Sales_item& rhs)
{
    if(amo.book()< rhs.book())
        return 1;
    else
        return 0;
}
