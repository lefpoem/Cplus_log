#include <iostream>
#include <string>
using namespace std;
void f(int *);
void f(int * const);
void s(int&);
void s(const int &);
bool (*pf)(const string &,const string &);
bool* pf(const string *,const string *);
