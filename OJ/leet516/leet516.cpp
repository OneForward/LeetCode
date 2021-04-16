/*
leet516


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
    int longestPalindromeSubseq1(string A) {
        // 动态规划, Time Space O(N^2), 276ms
        // 转化为一道 s 与 s 的逆串的最长公共子序列的题目
        int n = A.size();
        string B(A.rbegin(), A.rend());
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= n; ++j) { 
                if (A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        }
        return f[n][n];
    }
    int longestPalindromeSubseq2(string A) {
        // 动态规划, Time Space O(N^2), 276ms
        // 转化为一道 s 与 s 的逆串的最长公共子序列的题目
        int n = A.size();
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= n; ++j) { 
                if (A[i-1] == A[n-j]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i][j-1], f[i-1][j]);
            }
        }
        // cout << f;
        return f[n][n];
    }
    int longestPalindromeSubseq3(string A) {
        // 动态规划, Time O(N^2), Space O(N) 276ms
        // 转化为一道 s 与 s 的逆串的最长公共子序列的题目
        int n = A.size();
        vector<int> f(n+1);
        for (int i = 1; i <= n; ++i) { 
            int tmp = f[0];
            for (int j = 1; j <= n; ++j) { 
                if (A[i-1] == A[n-j]) swap(f[j], tmp), f[j]++;
                else tmp = f[j], f[j] = max(f[j-1], f[j]);
            }
            // cout << f;
        }
        return f[n];
    }
    int longestPalindromeSubseq(string A) {
        // 动态规划, Time O(N^2), Space O(N) 104ms
        // f(i, j) 直接统计 A[i..j] 之间的最长回文子序列的长度
        // 1. si == sj : f(i, j) = f(i+1, j-1) + 2
        // 2. ow. : f(i, j) = max(f(i+1, j), f(i, j-1))
        // 初始条件： f(i, i) = 1
        int n = A.size(), maxVal = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int j = 0; j < n; ++j) { 
            f[j][j] = 1;
            for (int i = j-1; i >= 0; --i) { 
                if (A[i] == A[j]) f[i][j] = f[i+1][j-1] + 2;
                else f[i][j] = max(f[i+1][j], f[i][j-1]);
                maxVal = max(f[i][j], maxVal);
            }
        }
        return maxVal;
    }
    int longestPalindromeSubseq5(string A) {
        // 动态规划, Time O(N^2), Space O(N) 104ms
        // 直接统计 A[j..i] 之间的最长回文子序列的长度
        // 旧的 f[j] 保存的是 A[j..i-1] 之间的最长回文子序列的长度
        // maxVal 保存的是 j 迭代过程中旧的 f[j] = max A[j..i-1] 的最大值
        int n = A.size(), maxVal;
        vector<int> f(n);
        for (int i = 0; i < n; ++i) { 
            f[i] = 1; maxVal = 0;
            for (int j = i-1; j >= 0; --j) { 
                int tmp = f[j];
                if (A[i] == A[j]) f[j] = maxVal + 2;
                maxVal = max(tmp, maxVal);
            }
            cout << f;
        }
        return *max_element(f.begin(), f.end());
    }
    int longestPalindromeSubseq6(string A) {
        // 动态规划, Time O(N^2), Space O(N) 104ms
        int n = A.size(), maxVal;
        int* f = new int[n]{};
        for (int i = 0; i < n; ++i) { 
            f[i] = 1; maxVal = 0;
            for (int j = i-1; j >= 0; --j) { 
                int tmp = f[j];
                if (A[i] == A[j]) f[j] = maxVal + 2;
                maxVal = max(tmp, maxVal);
            }

        }
        maxVal = 0;
        for (int i = 0; i < n; ++i) maxVal = max(maxVal, f[i]);
        return maxVal;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestPalindromeSubseq("bbbab") << endl;
    // cout << sol.longestPalindromeSubseq2("bbbab") << endl;
    cout << sol.longestPalindromeSubseq("cbbd") << endl;
    return 0;
}
