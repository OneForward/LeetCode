/*
leet485


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
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int ans = 0, cur = 0;
        for (const auto &x: nums) {
            cur = (x == 1) ? (cur+1) : 0;
            ans = max(cur, ans);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaxConsecutiveOnes({1,1,0,1,1,1}) << endl;
    return 0;
}
