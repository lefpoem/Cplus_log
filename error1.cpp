#include <iostream>
#include "Sales_item.h"
using namespace std;
istream& operator>>(istream& is ,Sales_item& atem){
    is >> atem;
    return is;
}
ostream& operator<<(ostream& os,const Sales_item& atok)
{
    os << atok;
    return os;
}
int main()
{
    Sales_item item1,item2;
    while(cin >> item1 >> item2)
    {
        try{
              // program-statements
        }catch(runtime_error err){ // handle-statements
            cout << err.what()
                 << "In Try Again? Enter y oy n" << endl;
            char c;
            cin >> c;
            if (cin && c=='n')
                break; //break out of the while loop
        }//catch block
    }
    if(!item1.same_isbn(item2))
      throw runtime_error ("Data must refer to same ISBN");
    //OK,if we'are still here the ISBNs are the same
    cout << item1+item2 << endl;
    return 0;   
}
