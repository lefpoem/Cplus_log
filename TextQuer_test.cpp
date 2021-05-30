#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include "make_plural.h"
#include "TextQuery.h"
using namespace std;
class TextQuery;
ifstream& open_file(ifstream &,const string &);
void print_results(const set<TextQuery::line_no> &,const string &,const TextQuery &);
int main(int argc,char **argv)
{
    //open the file from which users will query words
    ifstream infile;
    if (argc < 2 || !open_file(infile,argv[1]))
    {
       cerr << "No input file!" << endl;
       return EXIT_FAILURE;
    }
    TextQuery tq;
    tq.read_file(infile);//builds query map
    //loop indefinely:the loop exit is inside the while
    while(true){
        cout << "enter word to look for,or q to quit: " ;
        string s;
        cin >> s;
        //stop if hit eof on input or a 'q' is entered
        if (!cin || s == "q") break;
        //get the set of line numbers on which this word appears
        set<TextQuery::line_no> locs = tq.run_query(s);
        //print count and all occurrences,if any
        print_results(locs,s,tq);
    }
    return 0;     
}
ifstream& open_file(ifstream &in,const string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}
void print_results(const set<TextQuery::line_no> &pos, const string &st,const TextQuery &t)
{
    //if the word was found,then print count and all occurrences
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = pos.size();
    cout << "\n" << st << "occurs" << size << ""
         << make_plural(size,"time","s") << endl;
    //print each line in which the word appeared
    line_nums::const_iterator it = pos.begin();
    for ( ; it!=pos.end();++it)
    {
        cout << "\t (line"
             << (*it)+1 << ")"
             << t.text_line(*it) << endl;
    }
}
void TextQuery::store_file(ifstream &is)
{
    string textline;
    while(getline(is,textline))
        lines_of_text.push_back(textline);
}
void TextQuery::build_map()
{
    //process each line from the input vector
    for (line_no line_num = 0;line_num != lines_of_text.size();++line_num)
    {
        //we'll use line to read the text a word at a time
        string word;
        istringstream line(lines_of_text[line_num]);
        while(line >> word)
        {
            word_map[word].insert(line_num);
        }
    }
}
set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
    map<string,set<line_no> >::const_iterator loc = word_map.find(query_word);
    if(loc == word_map.end())
      return set<line_no>();//not found,return empty set
    else
       return loc->second;
}
string TextQuery::text_line(line_no line) const
{
    if(line < lines_of_text.size())
        return lines_of_text[line];
    throw out_of_range("line number out of range");
}