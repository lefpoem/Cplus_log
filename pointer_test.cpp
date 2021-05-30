#include <iostream>
using namespace std;
int main()
{
    int val(10);
    int m(5);
    int *p=&val;
    int **v;
    v = &p;
    *p=m;
    cout << p << endl
         << &p << endl
         << *p << endl
         << **v << endl;
}
