/*
leet1092


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // O(MN), 动态规划 + 模拟
        // 找到 LCS 后逐个将 s1 和 s2 中不在 LCS 中的字符填充上去即可
        // 可以事先构造好 LCS 的转移矩阵（记录了转移方向），然后逆推即可
        const int LFT = 0, UP = 1, LFTUP = 2;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        vector<vector<int>> path(n+1, vector<int>(m+1));
        
        for (int i = 0; i < n; i++) path[i+1][0] = UP;
        for (int i = 0; i < m; i++) path[0][i+1] = LFT;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j]) f[i+1][j+1] = f[i][j] + 1, path[i+1][j+1] = LFTUP;
                else if (f[i+1][j] > f[i][j+1]) {
                    f[i+1][j+1] = f[i+1][j]; path[i+1][j+1] = LFT;
                }
                else {
                    f[i+1][j+1] = f[i][j+1]; path[i+1][j+1] = UP;
                }
            }
            
        }
        
        string ans;
        int i = n, j = m;
        while (i > 0 or j > 0) {
            if (path[i][j] == LFTUP) 
                ans.push_back(s1[i-1]), i--, j--;
            else if (path[i][j] == LFT) 
                ans.push_back(s2[j-1]), j--;
            else 
                ans.push_back(s1[i-1]), i--;
        }


        return string(ans.rbegin(), ans.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.shortestCommonSupersequence("abac", "cab") << endl;
    cout << sol.shortestCommonSupersequence("abcbdab", "bdcaba") << endl;
    return 0;
}
