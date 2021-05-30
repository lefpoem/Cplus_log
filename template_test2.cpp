#include <string>
using namespace std;
template<class Type> Type sum(const Type &op1,int op2)
{
    return op1 + op2;
}
template<class T, class U> T num(T,U);
//T1 cannot to be deduced:it doesn't appear in the funtion parameter list
template<class T1,class T2,class T3> T1 sum(T2,T3);//无法进行模板推断
template<typename T> int compare(const T&,const T&);
void func(int(*)(const string&,const string&));
void func(int(*)(const int&,const int&));
int main(){
    double d=3.14;
    short s3=5;
    string s1("hiya"),s2("string");
    sum(1024,d);
    sum(1.4,d);
    //error :sum(s1,s2);s2 can't convert it to int
    num(s1,s3);
    func(compare<int>);//explicitly specify which version of func
    //eliminate ambiguity problems
    return 0;
}