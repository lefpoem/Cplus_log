#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;
class TextQuery
{
public:
    typedef vector<string>::size_type line_no;
    /*interface:
     *read_file builds internal data structures for the given file
     *run_query finds the given word and returns set of lines on 
     *which it appears
     *text_line returns a requested line from the input file
      */
    void read_file(ifstream &is)
    {
        store_file(is);//read file,store it to vector
        build_map(); // line is divide in word,build map
    }
    set<line_no> run_query(const string&) const;
    string text_line(line_no) const;
private:
    void store_file(ifstream&);
    void build_map();//associated each word with a set of line numbers
    vector<string> lines_of_text;
    map<string,set<line_no> > word_map;
};