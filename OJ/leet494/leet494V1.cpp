/*
leet494


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
#include <numeric>
using namespace std;

class Solution1 {
public:
    vector<int> A; int ans, sum, len;

    bool recursive(long long target, int last) {
        if (last == -1) {
            if (target == 0) {
                ans++; return true;
            }
            return false;
        }

        bool ok = false; 
        if (recursive(target-A[last], last-1)) { ok = true;}
        if (recursive(target+A[last], last-1)) { ok = true;}
        return ok;
    }
    int findTargetSumWays(const vector<int>& nums, int S) {
        // 1464ms, 递归解法
        A = nums; sum = ans = 0; 
        recursive(S, A.size()-1);
        return ans;
    }
};
class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int S) {
        // 动态规划, 0-1背包, 12ms
        if (S > 1000) return 0;
        int bias = accumulate(nums.begin(), nums.end(), 0);
        if (S > bias) return 0;
        vector<int> f(S+bias+1);
        f[0] = 1;
        for (const auto x: nums) {
           for (auto v = S+bias; v >= 2*x; --v) {
                f[v] += f[v - 2*x];
            }
        }
        return f[S+bias];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.findTargetSumWays({1,1,1,1,1}, 3) << endl;
    cout << sol.findTargetSumWays({1,0}, 1) << endl;
    return 0;
}
