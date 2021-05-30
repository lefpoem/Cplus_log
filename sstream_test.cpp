#include <iostream>
#include <sstream>
using namespace std; 
int main()
{
    int val1=512,val2=1024;
    ostringstream format_message;
    //ok: converts values to a string representation
    format_message << "val1: " << val1 << "\n"
                   << "val2: " << val2 << "\n";
    cout << format_message.str() <<endl;
    //str member obtains the string associated with a stringstream
    istringstream input_istring(format_message.str());
    string dump;//place to dump the labels from the formatted message
    //extracts the stored ASCII values,converting back to arithemetic types
    input_istring >> dump >> val1 >> dump >> val2;
    cout << val1 << "" << val2 << endl; //prints 512,1024
} 