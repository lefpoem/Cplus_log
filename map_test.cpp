#include <iostream>
#include <map>
using namespace std;
typedef map<string,int> smap;
int main()
{
    smap word_count;//empty map from string to int
    smap::value_type vat("m",1);//a pair type
    //deferencing to iterator will generate a object to a pair
    //get an iterator to an element in word_count
    smap::iterator map_it = word_count.begin();
    //*map_it is a reference to a pair<string,string> object
    cout << map_it->first; //prints the key for the element
    cout << " " << map_it->second;//prints the value of the element
    //map_it->first = "new key"; error :key is const
    ++map_it->second;//ok:we can change value through an iterator
    word_count["Anna"]=1;/*subscript access empty element,this will
    create a new element*/
    int occurs = word_count["foobar"];
    cout << word_count["Anna"] ;
    //fetch element indexed by Anna;prints 1
    ++word_count["Anna"];//fetch the element and add one to it
    cout << word_count["Anna"];//fetch element and print it;prints 2
    string word;
    while(cin >> word)
    {
        ++word_count[word];//prints 1,default 0
        pair<smap::iterator,bool> ret = word_count.insert(make_pair(word,1));
        //bool indicates whether the element is inserted
        if(!ret.second)//word; alreadt in word_count
          ++ret.first->second;//increment counter
    }
    //if anna not already in word_count,inserts new element with balue1
    word_count.insert(smap::value_type("Anna",1));//insert avoid usin intialization
    word_count.insert(make_pair("anna",1));//simplify value_type
    word_count.insert(vat);
    //insert return a pair from iterator to bool
    word_count.find("Anna");//return the times of "Anna"
    word_count.count("Anna");//exist,return the iterator,no exist return end()
    word_count.erase("Anna");//delete k,return size_type
    word_count.erase(map_it);
    word_count.erase(word_count.begin(),word_count.end());
    return 0;
}
