//Item sold at an undiscounted price
//derived classes will define various discount strategies
#include <string>
using namespace std;
class Base{
    friend class Frud;
public:
    Base(const Derived&);//create a new Base from a Derived
    Base& operator=(const Derived&);//assigned from a Derived
    size_t size() const {return n;}
protected:
    size_t n;
    int i;
};
class Derived: private Base{
public:
    //maintain access level for members related to the size of the object
    using Base::size;//using 权限提升
private:
    using Base::n;
};
//Frnd has no access to members in D1
class D1: public Base{
protected:
    int j;
};
class Frud{
public:
    int mem(Base b) {return b.i;}//ok:Frud is friend to Base
    int mem(D1 d) {return d.i;}//error:friendship doesn't inherit
};
/*无论基类派生多少个派生类，每个static成员只有一个实例，
既可以通过基类访问，也可以通过派生类访问*/
struct B
{
   static void statmem();
};
struct De: B
{
    void f(const De&);/* data */
};
void De::f(const De& De_obj)
{
    B::statmem();//ok:B defines statmem()
    De::statmem();//ok:De in herits statmem
    //ok:de objects can be used to access static from B
    De_obj.statmem();//accessed through this class
    statmem();//accessed through this class,equalivent to this.statmem()
}
class ZooAnimal{};
class Endagered{
public:
    void print(const Endagered&);
};
class Bear: public ZooAnimal{
public:
    void print(const Bear&);
};//don't allow to base class is declaration
class Panda: public Bear,public Endagered{
public:
    Panda(const string&){};
};
int main(){
    Panda ying_yang("ying");
    ying_yang.Endagered::print(ying_yang);//explicitly indicated call
}
