//复制构造函数就是接受单个类类型引用形参的构造函数
/* for a instance
class Foo{
public:
    Foo();//default constructor
    F00(const Foo&);
};
*/
#include <iostream>
#include <vector>
using namespace std;
class Foo{
public:
    Foo();//default constructor
    Foo(const Foo&);//copt constructor
    int& operator[] (const size_t);
    const int& operator[] (const size_t) const;
private:
    vector<int> data;
};
int& Foo::operator[] (const size_t index)
{
    return data[index];// no range checking index
}
const int& Foo::operator[] (const size_t index) const{
    return data[index];//no rangde checking on index
}
