#include <iostream>
#include "Sales_item.h"
#include <string>
using namespace std;
int main()
{
    string null_book = "9-999-99999-9";
    Sales_item item;
    //explicit converison:from string to Sales_item object
    item.same_isbn(Sales_item(null_book));
    //implicit conversion:from istream to Sales_item object
    item.same_isbn(cin);
}