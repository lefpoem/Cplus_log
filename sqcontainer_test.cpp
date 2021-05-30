#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "Sales_item.h"
#include <string>
using namespace std;
//container incorporates sequence container and associated container
//sequence container: vector list deque
//sequence container adapter: stack ,queue,priority_queue
//push_back:vector,list,deque
//push_front: list,deque
int main()
{
    vector<string> svec;
    //explicitly specify size_type
    vector< vector<string> > lines;//ok: space required between close >
    vector< vector<string>> lines2;//treats as shift operator
    const vector<int>::size_type list_size = 64;
    list<int> ilist(10,42);//list support not arithemetic and relational operator
    ilist.resize(15); //adds 5 elements of value 0 to back of ilist
    ilist.resize(25,-1);//adds 10 elements of value -1 to back of ilist
    ilist.resize(5);//erases 20elements from back of ilist
    if(!ilist.empty())
    {
        //val and val2 refer to the same element
        list<int>::reference val = *ilist.begin();
        list<int>::reference val2 = ilist.front();//front return the first element
        //last and last2 refer to the same element
        list<int>::reference last = *--ilist.end();
        list<int>::reference last2 = ilist.back();
        //c.at(n)or c[n] only is used for vector<int> and deque<int>
    }
    list<int> ilist2;
    ilist2.insert(ilist2.begin(),ilist.begin(),ilist.end());
    ilist2.erase(ilist2.begin(),ilist2.end());
    deque<Sales_item> items;
    vector<int> ivec;
    vector<int>::difference_type cnt;//difference_type can have negative value
    vector<int> ivec2(ivec);
    list<string> slit(svec.begin(),svec.end());
    vector<string>::iterator mid = svec.begin() + svec.size() /2;
    //initialize front with first half of svec: The elements up to but not includinh *mid
    deque<string> front(svec.begin(),mid);
    //initialize back with second half of svec:The elemnets *mid through end of svec
    deque<string> back(mid,svec.end());
    char *words[] = {"stately","plump","back","mulligan"};//C-style string
    //calculate how many elements in words
    size_t words_size = sizeof(words) / sizeof(char*);
    //use entire array to initialize words2
    list<string> words2(words,words+words_size);
    cout << sizeof(words) << endl;
    cout << sizeof(char*) << endl;
    cout << words_size << endl;
    cout << ilist.back() << endl;
    vector<int>::iterator first = ivec.begin(),last = ivec.end();
    //disaster:behavior of this loop is undefined
    while (first != last)
    {
        //do some processing
        //insert new value and reassign first,which otherwise would be invalid
        // after add,last is not either element of v or v.end();
        first = ivec.insert(first,42);
        ++first;
    }
    //safer:recalculate end on each trip whenever the loop adds/erases elements
    while(first != ivec.end())
    {
        first = ivec.insert(first,42);
        ++first;
    }
    return 0;
}