#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    const int pads = 2;

    cout << "input your name : ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";
    //int x = greeting.size() + 2 * pads + 2;
    const string::size_type x = greeting.size() + 2 * pads + 2; // unsigned long
    int y = 2 * pads + 2 + 1;

    for (int i = 0; i < y; ++i) {
        for (string::size_type j = 0; j < x; ++j) {
            if (i == 0 || i == y-1 || j == 0 || j == x-1)
                cout << "*";
            else if (i == pads + 1 && j == pads + 1) {
                cout << greeting;
                j = j + greeting.size() - 1;
            }
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
