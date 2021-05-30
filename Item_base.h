#include <string>
using namespace std;
class Item_base{
public:
    Item_base(const string &book=" ",double sales_price=0.0):
        isbn(book),price(sales_price){}
    string book() const {return isbn;}
    Item_base(const Item_base&);
    Item_base& operator=(const Item_base&);
    virtual double net_price(size_t n) const {return n*price;}
    virtual ~Item_base(){}//继承层次都需要析构函数
    virtual Item_base* clone() const{
        return new Item_base(*this);
    }
private:
    string isbn;
protected:
    double price;
};
//discount kicks in when a specified number of copies of same book are sold
//the discount is expressed as a fraction use to reduce the normal price
class Bulk_item: public Item_base
{
public:
    //redefine base version so as to implement bulk purchase discount policy
    double net_price(size_t) const;
    Bulk_item(const string &book,double sales_price,size_t qty=0,double disc_rate=0.0):
        Item_base(book,sales_price),min_qty(qty),discount(disc_rate){}
    Bulk_item* clone() const{
        return new Bulk_item(*this);
    }
private:
    size_t min_qty;//minumum purchases for discount to apply
    double discount;//fractional discount to apply
};
class Disc_item : public Item_base{
public:
    Disc_item(const string &book=" ",double sales_price=0.0,size_t qty=0,double disc_rate=0.0):
        quantity(qty),discount(disc_rate){}
    double net_price(size_t) const=0;//pure virtual function
protected:
    size_t quantity;//purchase size for discount to apply
    double discount;//fractional discount to apply
};
double Bulk_item::net_price(size_t cnt) const{
    if(cnt >= min_qty)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}
