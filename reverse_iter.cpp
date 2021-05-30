#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    //find first element in a comma-separated list
    string line;
    while (cin >> line) ;
    string::iterator comma = find(line.begin(),line.end(),',');
    cout << string(line.begin(),comma) << endl;
    //find last element in a comma-separated list
    string::reverse_iterator rcomma = find(line.rbegin(),line.rend(),',');
    //wrong:will generate the word in reverse order
    cout << string(line.rbegin(),rcomma) << endl;
    //ok:get a forward iterator and read to end of line
    cout << string(rcomma.base(),line.end()) << endl;
    return 0;
}
