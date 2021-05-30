#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    multimap<string,string> authors;
    authors.insert(make_pair(string("Barth,John"),string("Sot-Weed Factor")));
    authors.insert(make_pair(string("Barth,John"),string("lost in the home")));
    authors.insert(make_pair("Barth,JOhn","Lost forest"));
    string search_item("Kazuo,Ishguoro");
    //erase all elements with this kye; returns
    authors.erase("Barth,John");//multimap don't allow subscript operator
    typedef multimap<string,string>::size_type sz_type;
    sz_type entries = authors.count(search_item);
    map<string,string>::iterator iter = authors.find(search_item);
    for(sz_type cnt = 0;cnt!=entries;++cnt,++iter)
        cout << iter->second <<endl;  //print each title
    typedef map<string,string>::iterator map_it;
    map_it beg = authors.lower_bound(search_item);//returns the element of key>=k
    map_it end = authors.upper_bound(search_item);//returns the element of key>k
    //loop through the number of entries there are for this author
    while(beg!=end)
    {
        cout << beg->second << endl; //print each title
        ++beg;
    }
    //pos holds iterator that denote the range of elements for this key
    pair<map_it,map_it> pos = authors.equal_range(search_item);
    //equal_range returns a pair holds two iterator:first is lower_bound,second is upper_bound
    //loop through the number of entries there are for this authors
    while(pos.first!=pos.second)
    {
        cout << pos.first->second << endl;//print each title
        ++pos.first;
    }
    return 0;
}
