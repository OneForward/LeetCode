/*
leet561


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>&& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i += 2) { 
            ans += nums[i];
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.arrayPairSum({1,4,3,2}) << endl;
    cout << sol.arrayPairSum({6,2,6,5,1,2}) << endl;
    return 0;
}
