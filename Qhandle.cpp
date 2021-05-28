//private,abstract class acts as a base class for concrete query types
//句柄类存储和管理基类指针
#include "TextQuery.h"
#include "Item_base.h"
class Query_base
{
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() {}
private:
    //eval returns the set of lines that this Query matchs
    virtual set<line_no> eval(const TextQuery&) const=0;
    //display prints the query
    virtual ostream& display(ostream& = cout) const=0;
};
//use counted handle class for the Item_base hierachy
class Sales_item{
public:
    //default constructor: unbound handle
    Sales_item():p(0),use(new size_t(1)){}
    //attaches a handle to a copy of Item_base object
    Sales_item(const Item_base& item): p(item.clone()),use(new size_t(1)){}
    //copy control members to manager the use count and pointers
    Sales_item(const Sales_item& i):p(i.p),use(i.use) {++*use;}
    ~Sales_item() {decr_use();}
    Sales_item& operator= (const Sales_item& rhs){
        ++*rhs.use;//use count+1
        decr_use();
        p=rhs.p;
        use = rhs.use;
        return *this;
    }
    //member access operators
    const Item_base* operator->() const {
        if(p) 
            return p;
        else
            throw logic_error("unbound Sales_item");
    }
    const Item_base& operator*() const{
        if(p)
            return *p;
        else
            throw logic_error("unbound Sales_item");
    }
private:
    Item_base *p;//pointer to shared item
    size_t *use;//pointer to shared use count 
    //called by both destructor and assignment operator to free points
    void decr_use()
        {if(--*use==0){delete p;delete use;}}
};
