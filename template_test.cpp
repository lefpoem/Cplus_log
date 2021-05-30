#include <iostream>
#include <vector>
using namespace std;
//implement strcmp_like generic compare function
//return 0 if the values are equal,1 if the values are equal,-1 if v1 is smaller
template<typename T>
int compare(const T &v1,const T &v2)
{
    if(v1<v2) return -1;
    if(v2<v1) return 1;
    return 0;
}
template<class Type> class Queue
{
public:
    Queue();//default constructor
    Type& front();//return element from head of Queue
    const Type& front() const;
    void push(const Type&);// add element to back of Queue
    void pop();//remove element from head of Queue
    bool empty() const;//true if no elements in the Queue
private:
    //...
};
template<typename T> inline T min(const T&,const T&);
typedef double T;
template<class T> T calc(const T &a,const T &b)
{
    //tmp has the type of the template parameter T
    //not that of the global typedef
    //global is invisible to local
    T tmp = a;
    return tmp;
}
//initialize elements of an array to zero
template<class T,size_t N> void array_int(T (&parm)[N])
{
    for(size_t i=0;i!=N;++i)
        parm[i]=0;
}
int main()
{
    //T is int; compiler instantiates int compare(const int&,const int&)
    cout << compare(1,0) << endl;
    //T is string;compiler instantiates int compare(const string&,const string&)
    string s1="hi",s2="world";
    cout << compare(s1,s2) << endl;
    Queue<int> qi;//queue that holds int
    Queue< vector<double> > qc;//queue that holds vectors of doubles
    Queue<string> qs;//Queue that holds string
    return 0;
}