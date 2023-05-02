#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> titles;
    string line;
    vector<string>::size_type maxLen = 0;

    while(getline(cin, line)) {
        titles.push_back(line);
        //if (maxLen < line.size()) maxLen = line.size();
        maxLen = std::max(maxLen, line.size());
    }

    vector<string> frameTitles;
    frameTitles.push_back(string(maxLen + 4, '*'));

//    for (vector<string>::size_type i = 0; i < titles.size(); ++i) {
//        string space(maxLen - titles[i].size(), ' ');
//        //frameTitles[i] = "* " + titles[i] + space + " *";
//        frameTitles.push_back("* " + titles[i] + space + " *");
//    }
    for (vector<string>::const_iterator it = titles.cbegin(); it != titles.cend(); ++it) {
        string space(maxLen - it->size(), ' ');
        frameTitles.push_back("* " + *it + space + " *");
    }

    frameTitles.push_back(string(maxLen + 4, '*'));

//    for (vector<string>::size_type i = 0; i < frameTitles.size(); ++i) {
//        cout << frameTitles[i] << endl;
//    }
    for (vector<string>::const_iterator it = frameTitles.cbegin(); it != frameTitles.cend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
