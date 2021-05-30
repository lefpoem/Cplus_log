#include <iostream>
#include <vector>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item *p = new Sales_item[10];//dynamtic allocated
    vector<Sales_item> vec(p,p+10);//local object
    //...
    delete []p;//array is freed;destructor run on each element
    return 0;
}//vec goes out of scope;destructor run on each element
//总按逆序撤销，先size-1，后size-2
//动态对象，先删除指针，后删除对象，对象一直存在，会导致内存泄漏，任何资源都不会释放
//如果类需要析构函数，它也需要赋值操作符和复制构造函数
//不管是否定义析构函数，系统都会合成一个析构函数
