#include <iostream>
#include <vector>   // 가변길이 배열
#include <cstdlib>
#include "median.h"

using std::cin; using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> nums;

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int value = rand() % 100 + 1;
        nums.push_back(value);
    }

//    for (int i = 0; i < nums.size(); ++i){
//        cout << nums[i] << ", ";
//    }
//    cout << endl;

    int result = ::median(nums);    // :: calling global var
    cout << "median : " << result << endl;

    return 0;
}
