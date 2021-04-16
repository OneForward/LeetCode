/*
leet730


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


class Solution1 {
public:
    const int MOD = 1e9 + 7;
    int countPalindromicSubsequences1(string S) {
        // 384ms, 动态规划
        // f(i, j, a) 代表 S[i..=j] 中中两端都是 a 的 *不同* 回文串的数目
        // if S[i] != a : f(i, j, a) = f(i+1, j, a)
        // if S[j] != a : f(i, j, a) = f(i, j-1, a)
        // if S[i] == S[j] == a : f(i, j, a) = 2 + \sum f(i+1, j-1, *)
        // 最后一个是因为 包含了 a 和 aa 两个回文串，其余都是 a..a 形式的，注意内部非空
        int n = S.size();
        vector<vector<vector<int>>> f(4, vector<vector<int>>(n, vector<int>(n)));
        for (int i = 0; i < n; ++i) { 
            for (int k = 0; k < 4; ++k) { 
                if (S[i] - 'a' == k) f[k][i][i] = 1;
            }
        }

        for (int i = n-2; i >= 0; --i) { 
            for (int j = i+1; j < n; ++j) { 
                for (int k = 0; k < 4; ++k) { 
                    if (S[i] - 'a' != k) f[k][i][j] = f[k][i+1][j];
                    else if (S[j] - 'a' != k) f[k][i][j] = f[k][i][j-1];
                    else {
                        f[k][i][j] = 2;
                        for (int ki = 0; ki < 4; ++ki) { 
                            f[k][i][j] += f[ki][i+1][j-1];
                            f[k][i][j] %= MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int k = 0; k < 4; ++k) { 
            ans += f[k][0][n-1];
        }
        return ans % MOD;
    }

    int countPalindromicSubsequences2(string S) {
        // TLE 原因在于循环顺序的问题
        // 动态规划
        // f(i, j, a) 代表 S[i..=j] 中中两端都是 a 的 *不同* 回文串的数目
        // if S[i] != a : f(i, j, a) = f(i+1, j, a)
        // if S[j] != a : f(i, j, a) = f(i, j-1, a)
        // if S[i] == S[j] == a : f(i, j, a) = 2 + \sum f(i+1, j-1, *)
        // 最后一个是因为 包含了 a 和 aa 两个回文串，其余都是 a..a 形式的，注意内部非空
        int n = S.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < n; ++i) { 
            for (int k = 0; k < 4; ++k) { 
                if (S[i] - 'a' == k) f[i][i][k] = 1;
            }
        }

        for (int i = n-2; i >= 0; --i) { 
            for (int j = i+1; j < n; ++j) { 
                for (int k = 0; k < 4; ++k) { 
                    if (S[i] - 'a' != k) f[i][j][k] = f[i+1][j][k];
                    else if (S[j] - 'a' != k) f[i][j][k] = f[i][j-1][k];
                    else {
                        f[i][j][k] = 2;
                        for (int ki = 0; ki < 4; ++ki) { 
                            f[i][j][k] += f[i+1][j-1][ki];
                            f[i][j][k] %= MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int k = 0; k < 4; ++k) { 
            ans += f[0][n-1][k];
        }
        return ans % MOD;
    }

};

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> M, next, prev;
    int dp( int i, int j ) {
        // M[i][j] ： 分别计算 S[i..=j] 中以 a..a , b..b 形式的回文串
        // 先找到 i, j 中最左边和最右边的 a, 记为 i0, j0
        // i0 == -1 说明不存在
        // i0 == j0 只有 1 个回文串 a
        // i0 < j0  f(i, j) = f(i+1, j-1) + 2, 2 是指 a 和 aa 两个串, 其余的都是 a..a 且内部非空的回文串
        if (M[i][j]) return M[i][j];
        
        if (i == j) return 1;
        if (i > j) return 0;

        long long ans = 0;
        for (int k = 0; k < 4; ++k) { 
            auto i0 = next[i][k], j0 = prev[j][k];
            if ( i0 == -1 ) continue;
            if ( i0 == j0 ) ans++;
            if ( i0 <  j0 ) ans += 2 + dp(i0+1, j0-1);
        }
        ans %= MOD;
        M[i][j] = ans;
        return ans;
    }

    int countPalindromicSubsequences(string S) {
        // 72ms, 动态规划, 自顶向下
        int n = S.size();
        M.resize(n, vector<int>(n));
        next.resize(n);
        prev.resize(n);
        vector<int> last = {-1, -1, -1, -1};
        for (int i = 0; i < n; ++i) {
            last[S[i]-'a'] = i;
            prev[i] = last;
        }
        last = {-1, -1, -1, -1};
        for (int i = n-1; i >= 0; --i) {
            last[S[i]-'a'] = i;
            next[i] = last;
        }
        return dp(0, n-1);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;  
    cout << sol.countPalindromicSubsequences("acaccbbdcddaacddaccd") << endl;
    cout << sol.countPalindromicSubsequences("bccb") << endl;
    cout << sol.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << endl;
    return 0;
}
