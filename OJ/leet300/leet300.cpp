#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

class Solution1 {
public:
    int lengthOfLIS(const vector<int>& A) {
        // O(N^2)
        int N = A.size();
        vector<int> ans(N);
        for (size_t rht = 0; rht < N; rht++)
        {
            auto curMax = 1;
            for (size_t lft = 0; lft < rht; lft++)
            {
                if (A[lft] < A[rht]) curMax = max(curMax, ans[lft]+1);
            }
            ans[rht] = curMax;
        }
        return *max_element(ans.begin(), ans.end());
    }
};



class Solution {
public:
    int lengthOfLIS(const vector<int>& A) {
        // O(N log N) , 贪心 + 二分
        // tails[i] 保存的是长度为 i 的 LIS 的末端值，保证这个末端值尽可能小
        // 任何一个新晋 x: 我们找到它的位置 i (lower_bound, 第一个 A[i] >= x > A[i-1])
        // 假如 x < A[i] : 我们减少 A[i] = x, 这样对于新晋的 y > x， 我们必能找到 i 之后 的位置给 y
        vector<int> tails; 
        for (const auto& x: A) {
            auto pos = lower_bound(tails.begin(), tails.end(), x);
            if (pos == tails.end()) tails.push_back(x);
            else  *pos = x;
        }
        return tails.size();
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
