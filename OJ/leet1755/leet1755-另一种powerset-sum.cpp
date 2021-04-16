/*
leet1755


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
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

// https://leetcode-cn.com/problems/closest-subsequence-sum/solution/zhuang-ya-dp-zhi-cong-kan-shu-ju-fan-wei-kve3/
class Solution {
public:
    int minAbsDifference(const vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        int ls = half, rs = n - half;
        
        vector<int> lsum(1 << ls, 0);
        for (int i = 1; i < (1 << ls); i++) {
            for (int j = 0; j < ls; j++) {
                if ((i & (1 << j)) == 0) continue;
                lsum[i] = lsum[i-(1<<j)] + nums[j];
                break;
            }
        }
        vector<int> rsum(1 << rs, 0);
        for (int i = 1; i < (1 << rs); i++) {
            for (int j = 0; j < rs; j++) {
                if ((i & (1 << j)) == 0) continue;
                rsum[i] = rsum[i-(1<<j)] + nums[ls+j];
                break;
            }
        }
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        
        int ret = INT_MAX;
        for (int x: lsum) {
            ret = min(ret, abs(goal - x));
        }
        for (int x: rsum) {
            ret = min(ret, abs(goal - x));
        }
        
        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            ret = min(ret, abs(goal - s));
            if (s > goal) {
                j--;
            } else {
                i++;
            }
        }
        return ret;
    }
};
 

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.minAbsDifference({5,-7,3,5}, 6) << endl;
    cout << sol.minAbsDifference({7,-9,15,-2}, -5) << endl;
    // cout << sol.minAbsDifference({1,2,3}, -7) << endl;
    return 0;
}
