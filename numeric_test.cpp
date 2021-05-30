#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include "word_cnt.h"
using namespace std;
int main()
{
    string next_word;
    vector<string> svec;
    while (cin >> next_word)
        svec.push_back(next_word);
    vector<int> ivec;
    int sum = accumulate(ivec.begin(),ivec.end(),42);
    //concatenet elements from v and store in sum
    string sun = accumulate(svec.begin(),svec.end(),string(""));
    size_t cnt = 0;
    list<int> ilist;
    list<string> roster1,roster2;
    list<string>::iterator it = roster1.begin();
    while ((it = find_first_of(it,roster1.end(),roster2.begin(),roster2.end()))!=roster1.end())
    {
         ++cnt;
         ++it;
    }
    fill(ivec.begin(),ivec.end(),0);
    fill(ivec.begin(),ivec.begin()+ivec.size()/2,10);
    fill_n(back_inserter(ivec),10,0);
    copy(ilist.begin(),ilist.end(),back_inserter(ivec));
    //vector<int> ivec(ilist.begin(),ilist.end());
    //replace any element with value of 0 by 42
    replace(ilist.begin(),ilist.end(),0,42);
    //create back_inserter to grow destination as needed
    replace_copy(ilist.begin(),ilist.end(),back_inserter(ivec),0,42);
    //text: the quick red fox jumps over the slow red turtle
    sort(svec.begin(),svec.end());
    /*eliminate duplicate words:
     *unique recorders words so that each word appears one in the front
     *portion of words and returns an iterator one past the unique range
     *erase uses a vector operation to remove the nonunique elements
     */
    vector<string>::iterator end_unique = unique(svec.begin(),svec.end());
    svec.erase(end_unique,svec.end());
    //sort words by size,but maintain alphabetic order for words of the same size
    stable_sort(svec.begin(),svec.end(),isShorter);
    for(vector<string>::const_iterator it = svec.begin();it!=svec.end();++it)
    {
        cout << " " << *it ;
    }
    cout << endl;
    //after sort  :fox jumps over quick red red slow the the turtle
    //after unqiue:fox jumps over qucik red slow the turtle the turtle
    //after erase :fox jumps over qucik red slow the turtle
    //after stable:fox red the over slow jumps quick turtle
    vector<string>::size_type wc = count_if(svec.begin(),svec.end(),GT6);
    vector<string>::size_type mc = count_if(svec.begin(),svec.end(),GT_cls(5));
    cout << count_if(svec.begin(),svec.end(),GT_cls(6));
    for(size_t i=0;i!=11;++i)
        cout << count_if(svec.begin(),svec.end(),GT_cls(i))
            <<" words " << i
            <<" characters or longer" << endl;
}
