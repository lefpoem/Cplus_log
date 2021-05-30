#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
   ifstream infile;
   ofstream outfile;
   outfile.open("out");//open file named "out" in current directory
   infile.open("in"); //open file named "in" in current directory
   //check that the open succeeded
   ostream& operator<<(ostream& os,ifstream& in);
   if(!infile){
       cerr << "error: unable to input file: " << infile << endl;
   }
   ifstream mfile("in"); //opens file named "in" for reading
   mfile.close(); //closes "in"
   mfile.open("next"); //opens file name "next" for reading
   fstream inOut ("copyOut",fstream::in | fstream::out);//open for input and output
   //append mode : adds new data at the end of existing file named "file2"
   ofstream appfile("file2",ofstream::app);
   //"file1" is explicitly turncated
   ofstream outfile2("file1",ofstream::out | ofstream::trunc);
   return 0;
}
