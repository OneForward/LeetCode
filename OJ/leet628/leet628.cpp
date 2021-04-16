/*
leet628


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

// namespace my{
//     void sort()
// }

class Solution {
public:
    int maximumProduct(vector<int>&& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int P1 = nums[0], P2 = nums[1], P3 = nums[2];
        int len = nums.size();
        int N1 = nums[len-1], N2 = nums[len-2];
        
        return max(P1 * P2 * P3, P1 * N1 * N2);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maximumProduct({1,2,3,4});
    return 0;
}
