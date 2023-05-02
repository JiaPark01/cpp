#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> words;
    vector<int> counts;

    string word;
    while (cin) {       // istream --> bool. until nothing entered
        cin >> word;
        vector<string>::size_type i;
        for (i = 0; i < words.size(); ++i) {
            if (word == words[i]) break;
        }

        if (i == words.size()) {
            words.push_back(word);
            counts.push_back(1);
        } else ++counts[i];
    }

    for (vector<string>::size_type i = 0; i < words.size(); ++i) {
        cout << words[i] << " : " << counts[i] << endl;
    }

    return 0;
}
