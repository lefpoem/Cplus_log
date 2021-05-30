#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string word;
    vector<string> text;//empty vector
    vector<int> ivec;
    while(cin >> word)
    {
        text.push_back(word); //append word to vector
    }
    for(vector<int>::size_type ix = 0;ix!= ivec.size();++ix)
        ivec[ix]=0;
    for(vector<string>::size_type tx = 0;tx!= text.size();++tx)
        text[tx]=0;
    for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
       *iter=0;
    return 0;
}