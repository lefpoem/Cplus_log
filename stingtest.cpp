/*getline ignore not newline*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string river("Mississippi");
    string::size_type first_pos = river.find("is");//return 1
    string::size_type last_pos = river.rfind("is"); //return 4
    string *ps1,ps2;//ps1 is a pointer,ps2 is a string
    string st("The expense of spirt \n");
    cout << "The size of " << st << "is " <<st.size()
         << " characters, including the newline" << endl;
    return 0;
}
string s1="m";
string s=(s1+",");
//string s2=(","+"hello"+"s1"); two operand need a sting operator.