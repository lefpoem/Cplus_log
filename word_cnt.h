#include <string>
using namespace std;
//predict function
//comparison function to be used to sort by word length
bool isShorter (const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
//determine whether  a length of a word is 6 or more
bool GT6(const string &s)
{
    return s.size() >= 6;
}
class GT_cls{
public:
    GT_cls(size_t val=0):bound(val){}
    bool operator()(const string &s)
    {
        return s.size() >= bound;
    }
private:
    string::size_type bound;
};