#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;


inline int lowbit(int x) { return x & -x; }

class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        // 用树状数组找到在小于当前数字的数中，递增序列长度的最大值。(类似区间极大值)
        // 树状数组求区间极大值时，只要区间是从 1 开始的，就可以直接用区间和的思路
        vector<int> A = nums;
        sort(A.begin(), A.end());

        int *tree = new int[nums.size() + 1]{}; int ans = 0;
        for(int x : nums)
        {
            int before = 0;
            int rk = lower_bound(A.begin(), A.end(), x) - A.begin();
            for(int t = rk; t > 0; t -= lowbit(t)) before = max(before, tree[t]);
            for(int t = rk + 1; t <= nums.size(); t += lowbit(t)) tree[t] = max(tree[t], before + 1);
            ans = max(ans, before + 1);
        }
        return ans;
    }
};
 

int main(int argc, char **argv)
{
	vector<int> A{2,2};
    Solution sol;
    cout << sol.lengthOfLIS({10,9,2,5,3,7,101,18}) << endl;
    cout << sol.lengthOfLIS({0,1,0,3,2,3}) << endl;
    cout << sol.lengthOfLIS({7,7,7,7,7,7,7}) << endl;
	return 0;
}
