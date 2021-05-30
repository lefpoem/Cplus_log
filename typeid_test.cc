#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    int iobj;
    cout << typeid(iobj).name() << endl;
}