#include <iostream>
//iostate: bad,fail,eof,good
using namespace std;
int main()
{
    int ival;
    while(cin >> ival,!cin.eof())
    {
        if(cin.bad())
           throw runtime_error("IO steam corrupted");
        if(cin.fail())
           cerr << "bad data,try again";
        cin.clear(istream::failbit);//badbit corruped,failbit can reset;
        continue;
    }
    return 0;
    cout << "HI" << flush; //flushes the buffer ;adds no data;
    cout << "HI" << ends; //inserts a null,then flushes the buffer
    cout << "HI" << endl;  //inserts a newline,then flushes the buffer
    cin.tie(&cout); //cin ties cout
    cin.tie(0);//break ties to cout
}
