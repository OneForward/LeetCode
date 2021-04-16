/*
leet213


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
using namespace std;

class Solution1 {
public:
    int rob_sub(int* A, int lft, int rht) {
        // 0ms, 动态规划, 环状DP
        // f[i] = max(f[i], f[i-2] + A[i])
        int f1 = A[lft], f2 = 0;
        for (int i = lft+1; i < rht; ++i) {
            auto tmp = f1;
            f1 = max(f1, f2 + A[i]);
            f2 = tmp;
        }
        return f1;
    }
    int rob(const vector<int>& nums) {
        // 0ms, 动态规划, 环状DP, O(N^2) 做法
        int n = nums.size();
        int* A = new int[2 * n];
        int i = 0;
        for (const auto x: nums) A[i++] = x;
        for (const auto x: nums) A[i++] = x;

        int ans = 0;
        for (int lft = 0; lft < n; ++lft) {
            ans = max(ans, rob_sub(A, lft, lft+n-1 ));
        }

        return ans;
    }
};
class Solution {
public:
    int rob(const vector<int>& nums) {
        // 0ms, 动态规划, 环状DP, O(N) 做法
        // 只需注意 第一个房子要，则最后一个房子不要，则是线性原问题
        // 或者 第一个房子不要，则是线性原问题
        int n = nums.size(), ans = 0;
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int f1 = nums[0], f2 = 0;
        for (int i = 1; i < n-1; ++i) {
            auto tmp = f1;
            f1 = max(f1, f2 + nums[i]);
            f2 = tmp;
        }
        ans = f1;

        f1 = 0, f2 = 0;
        for (int i = 1; i < n; ++i) {
            auto tmp = f1;
            f1 = max(f1, f2 + nums[i]);
            f2 = tmp;
        }
        ans = max(ans, f1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.rob({1}) << endl;
    cout << sol.rob({2,3,2}) << endl;
    cout << sol.rob({1,2,3,1}) << endl;
    cout << sol.rob({2,7,9,3,1}) << endl;
    return 0;
}
