//if precomplier
#ifndef MAKE_PLURAL
#define MAKE_PLURAL
#include <string>
using namespace std;
string make_plural(size_t ct,const string& word,const string ending)
{
    return (ct==1)? word:ending;
}
#endif
