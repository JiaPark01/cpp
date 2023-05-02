#include <algorithm>
#include <vector>
#include "median.h"

using std::vector;

int median(const vector<int>& vec)
{
    vector<int> nums = vec;

    std::sort(nums.begin(), nums.end());

    const vector<int>::size_type size = nums.size();
    int result = (size/ 2) ? nums[size/2] : (nums[size/2] + nums[size/2-1]) / 2;

    return result;
}