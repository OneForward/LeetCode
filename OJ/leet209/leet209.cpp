/*
leet209


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

class Solution {
public:
    int minSubArrayLen(int s, const vector<int>& nums) {
        // O(N)
        int n = nums.size();
        if (n == 0) return 0;

        int ans = n + 1;
        vector<int> sum(n), prev(n);
        sum[0] = nums[0];
        if (sum[0] >= s) return 1;
        for (int i = 1; i < n; ++i) { 
            prev[i] = prev[i-1];
            sum[i] = sum[i-1] + nums[i];
            while (sum[i] - nums[prev[i]] >= s) {
                sum[i] -= nums[prev[i]++];
            }
            if (sum[i] >= s) ans = min(ans, i - prev[i] + 1);
        }
        
        return ans == (n + 1) ? 0 : ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.minSubArrayLen(7, {2,3,1,2,4,3}) << endl;
    // cout << sol.minSubArrayLen(10, {10,2,3}) << endl;
    cout << sol.minSubArrayLen(3, {1,1}) << endl;
    return 0;
}
