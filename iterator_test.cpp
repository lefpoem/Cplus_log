#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_item.h"
using namespace std;
//three iterator:inserter,reverse itereator,iostream iterator
//three inserter:insertor(any position),back_inserter,front_inserter
int main()
{
    list<int> ilist,ilist2,ilist3;//empty lists
    //afeter this loop ilist contains:3 2 1 0
    for(list<int>::size_type i = 0; i!=4;++i)
       ilist.push_front(i);
    //after copy ilst2 contains:0 1 2 3
    copy(ilist.begin(),ilist.end(),front_inserter(ilist2));
    //afet copy,ilist3 contains:3 2 1 0
    copy (ilist2.begin(),ilist2.end(),inserter(ilist3,ilist3.begin()));
    istream_iterator<int> in(cin);//reads ints from cin
    istream_iterator<int> eof; //end iterator value
    //writes Sales_item from the named outfile
    //each element is followed by a space
    ofstream outfile;
    ostream_iterator<Sales_item> output(outfile," ");
    vector<int> vec(in,eof);
    while(in!=eof)
    {
        vec.push_back(*in++);
    }
    //write ont string perline to the standard output
    ostream_iterator<int> out_iter(cout,"\n");
    //read strings from standard input and the end iterator
    istream_iterator<int> in_iter(cin),eof;
    //read until eof and write what was read to the standard output
    while(in_iter!=eof)
        //write value fo in_iter to standard output
        //and then increment the iterator to get the next value from cin
        *out_iter = *in_iter++;
        //one read,one run
    return 0;
} 
