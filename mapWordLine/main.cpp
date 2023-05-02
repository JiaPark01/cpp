#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using std::cin; using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

bool isSpace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

bool isNotSpace(char c)
{
    return !isSpace(c);
}

void split(const string& s, vector<string>& words)
{
    //string::size_type i = 0;
    string::const_iterator it = s.begin();
    while (it != s.end()) {
        it = std::find_if(it, s.end(), isNotSpace);
        
        string::const_iterator it2;
        it2 = std::find_if(it, s.end(), isSpace);

        if (it != s.cend()) {
            words.push_back(string(it, it2));
        }

        it = it2;
    }

//    while (i != s.size()) {
//        while (i != s.size() && isSpace(s[i])) {
//            ++i;
//        }
//
//        string:: size_type j = i;
//
//        while (j != s.size() && !isSpace(s[j])) {
//            ++j;
//        }
//
//        if (i != j) {
//            words.push_back(s.substr(i, j-i));
//            i = j;
//        }
//    }

    //vector<string> words;

    //return words;
}

int main() {
    map<string, int> wordCounts;
    map<string, vector<int> > wordLines;

    string s;
    int i = 0;
    while(getline(cin, s)) {
        vector<string> v;
        split(s, v);
        for (auto it = v.cbegin(); it != v.cend(); ++it) {
            //++wordCounts[*it];
            wordLines[*it].push_back(i);
        }
        ++i;
    }

    for (auto it = wordLines.cbegin(); it != wordLines.cend(); ++it) {
        cout << it->first << " : ";
        for (auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2) {
            cout << *it2 << ", ";
        }
        cout << endl;
    }

    return 0;
}
