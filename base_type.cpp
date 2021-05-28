#include<iostream>
using std::cout;
using std::endl;
struct Base {
    Base():mem(0){}
protected:
    int mem;
};
struct Derived : Base
{
    Derived(int i): mem(i) {}
    int get_mem(){return mem;}
protected:
    int mem;
    }; 
int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;//prints 42
    return 0;
}
