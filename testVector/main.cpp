#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<int> v1;     // default constructor
    vector<int> v2(10); // create 10 spaces from the beginning since push_back keeps creating new array with 2x size

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //vector<int> v3 (nums, 10);
    vector<int> v3(nums, nums + 10);    // using iterator

    vector<int> v4 = v3;

    return 0;
}
