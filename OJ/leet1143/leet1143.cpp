/*
leet1143


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

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        // 动态规划, Time Space O(MN), 36ms
        int n = A.size(), m = B.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= m; ++j) { 
                if (A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        }
        return f[n][m];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    cout << sol.longestCommonSubsequence("abc", "abc") << endl;
    cout << sol.longestCommonSubsequence("abc", "def") << endl;
    return 0;
}
