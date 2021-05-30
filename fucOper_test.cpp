#include <functional>
using namespace std;
struct absInt
{
    int operator()(int val)/* defines function call opertor*/{
        return val<0? -val:val;
    }        
};
class SmallInt{
public:
    SmallInt (int i=0):val(i)
    {
        if(i<0 || i>255)
            throw out_of_range("Bad SmallInt initializer");
    }
    SmallInt (double);//from double to SmallInt
    //conversions to int or double from SmallInt
    //Usually it is unwise to define conversions to multiple arithmetic types
    operator double() const {return val;}//from SmallInt to double
    operator int() const {return val;}//type conversion operator type()
    //no return ,no parameter
private:
    size_t val;
};
class Integral{
public:
    Integral(int i=0):val(i) {}//convert i to integral
    operator SmallInt() const {return val%256;}
private:
    size_t val;
};
int main()
{
    void compute(int);
    void compute(double);
    SmallInt si;
    //avoid to generate ambiguity problems
    coumpute(static_cast<int>(si)); //ok:convert and call compute(int)
    int calc(int);
    Integral intval;
    SmallInt si(intVal);//ok:convert intVal to SmallInt and copy tosi
    int i = calc(si);//ok:convert si to int and call calc
    int j = calc(intVal);//ok: convert Integral to int 
    int i=-42;
    absInt absObj; //obeject that defines function call opertor
    unsigned int ui= absObj(i); //calls absInt::opertor(int)
    plus<int> intAdd;//function object that can add two int values
    negate<int> intNegate;//fuction object that can negate an int value
    //uses intAdd::operator(int,int) to add 10 and 20
    int sum=intAdd(10,20);//sum=30
    //uses intNegate::operator(int) to generate -10 as second parameter
    //to intAdd::operato(int,int)
    int num=intAdd(10,intNegate(10));//num 0;
    return 0;
}
