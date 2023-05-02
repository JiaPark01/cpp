#include <iostream>
#include <vector>
#include <random>

using std::cin; using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);  // uniform b/w 0 to 99

    vector<int> nums;

    for (int i = 1; i <= 100; ++i) {
        int num = dis(gen);
        nums.push_back(num);
    }

    vector<int>::size_type sum = 0;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
        sum += *it;
    }
    double avg = sum * 1.0 / 100;

    cout << "sum : " << sum << "\tavg : " << avg << endl;

    return 0;
}
