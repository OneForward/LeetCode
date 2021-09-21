/*
leet673


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(const vector<int>& A) {
        // O(N^2), 动态规划
        //   len[i]: 保存以 A[i] 为终点的 LIS 的长度
        // count[i]: 保存以 A[i] 为终点的 LIS 的个数
        // 对于 j < i, A[j] < A[i], 则 len[i] = max(len[j]+1, len[i])
        // 对于贡献了 len[i] = len[j] + 1 的 j, count[i] += count[j]
        // 最后 ans 等于所有 len[i] = maxlen 的 i 贡献的 count[i] 之和
        int n = A.size();
        vector<int> len(n), count(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[j] < A[i]) {
                    if (len[i] < len[j] + 1) len[i] = len[j] + 1, count[i] = count[j];
                    else if (len[j] + 1 == len[i] ) count[i] += count[j];
                }
            }
        }
        int maxlen = *max_element(len.begin(), len.end());;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (len[i] == maxlen) ans += count[i];
        }
        cout << len << endl;
        cout << count << endl;
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findNumberOfLIS({1,3,5,4,7}) << endl;
    cout << sol.findNumberOfLIS({2,2,2,2,2}) << endl;
    cout << sol.findNumberOfLIS({1,2,4,3,5,4,7,2}) << endl;
    return 0;
}
