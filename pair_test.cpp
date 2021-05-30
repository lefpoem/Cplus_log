//associated container hash
//associated container modality is key-
#include <iostream>
#include <utility>
using namespace std;
typedef pair<string,string> author;
int main()
{
    author proust("Marcel","Proust");
    author joyce("James","JOyce");
    string firstbook;
    if (proust.first == "James"&& proust.second == "JOyce")
       firstbook = "Stephen Hero";
    author next_auth;
    string first,last;
    while (cin >> first >> last) {
        //generate a pair from first and last
        next_auth = make_pair(first,last);
        //process next_auth...
    }
}
