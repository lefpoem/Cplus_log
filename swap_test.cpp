#include <iostream>
using namespace std;
void swap(int& i,int& j);
void do_swap(int& i,int& j);
int main()
{
    int j=10,i=20;
    cout << "Before swap() : \t i: "
         << i << "\t j: " << j << endl;
    swap(i,j);
    cout << "After swao(): \t i: "
         << i << "\t j: " << j << endl;
    return 0;
}
void swap(int& i ,int& j)
{
    if (i==j)
       return ; // return will close this function compulsively
    return do_swap(i,j);// they can return call function
}
inline void do_swap(int& i,int &j)
{
    int temp=i;
    i=j;
    j=temp;
}
int& mm(int& s)
{
    int ret =s;
    return ret;
}
//int m =ret; don't use local object to assign m; 