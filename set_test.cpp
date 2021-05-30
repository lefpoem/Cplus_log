#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>
//define a vector with 20 elements,holding two copies of each numeber from 0~9
#include <vector>
using namespace std;
int main()
{
    vector<int> ivec;
    for(vector<int>::size_type i =0;i!=10;++i){
        ivec.push_back(i);
        ivec.push_back(i);//duplicate copies of each number
    }
    //iset holds unique elements from ivec
    set<int> iset(ivec.begin(),ivec.end());//initailize set by vector
    cout << ivec.size() << endl;  //prints 20
    cout << iset.size() << endl;  //prints 10
    set<string> set1;//empty set
    set1.insert("the"); //set1 has one element now
    set1.insert("and"); //set1 now has two elements
    set<int> iset2; //empty set
    iset2.insert(ivec.begin(),ivec.end());
    iset.find(1); //returns iterator that refer to key==1
    iset.find(11); //returns iterator == iset.end()
    iset.count(1); //returns 1(existing)
    iset.count(11); //returns 0 (not existing)
    //set_it refers the element with key==1
    set<int>::iterator set_it = iset.find(1);
    cout << *set_it << endl;
    return 0;
}
void restricted_wc(ifstream &remove_file,map<string,int> &word_count)
{     //"remove_word" set
    set<string> excluded; //set to hold words will ignore
    string remove_word;
    while(remove_file >> remove_word)
    {
        excluded.insert(remove_word);
    }
    //read input and keep a count for words that aren't in the exclusion set
    string word;
    while (cin >> word)
    {
        //increment counter only if the word is not in excluded
        if(!excluded.count(word))
           ++word_count[word];
    }
}