/*
leet005


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
    string longestPalindrome1(string s) {
        // Time O(n^2), Space O(n^2), 1296ms, 动态规划
        int n = s.size();

        vector<vector<bool>> f(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) { 
            f[i][i] = true;
        }
        for (int i = 0; i < n-1; ++i) { 
            if (s[i] == s[i+1]) f[i][i+1] = true; 
        } 

        for (int i = n-2; i >= 0; --i) { 
            for (int j = i+2; j < n; ++j) { 
                f[i][j] = f[i+1][j-1] && s[i] == s[j]; // 算法核心，转移函数
            }
        }
        int len = 0, start = 0;
        for (int i = 0; i < n; ++i) { 
            for (int j = i; j < n; ++j) { 
                if (f[i][j] && j - i + 1 > len) len = j - i + 1, start = i;
            } 
        } 
        return s.substr(start, len);
    }

    string longestPalindrome2(string s) {
        // 中心扩散算法
        // Time O(n^2), Space O(1), 96ms
        int n = s.size();
        int len = 0, start = 0;
        for (int i = 0; i < n; ++i) { 
            for (int k = 0; k <= min(i, n-1-i); ++k) { 
                if (s[i-k] != s[i+k]) break;
                else if (2 * k + 1 > len) len = 2 * k + 1, start = i - k;
                
            }
            for (int k = 0; k <= min(i, n-2-k); ++k) { 
                if (s[i-k] != s[i+1+k]) break;
                else if (2 * k + 2 > len) len = 2 * k + 2, start = i - k;
            }
        }
        return s.substr(start, len);
    }
    string longestPalindrome(string s) {
        // Manacher 算法
        // Time O(n), Space O(n), 12ms
        vector<char> v = {'$', '.'};
        for (const auto ch: s) {
            v.push_back(ch);
            v.push_back('.'); 
        }
        v.push_back('%');

        string snew(v.begin(), v.end());
        vector<int> p(snew.size());

        // https://www.zhihu.com/question/37289584/answer/465656849
        // C 表示回文串的中心，用 R 表示回文串的右边半径坐标，
        // 所以 R = C + P[ C ] 。
        // C 和 R 所对应的回文串是当前循环中 R 最靠右的回文串
        // p[i] 储存 snew 中以 i 为中心的回文串的 左右臂长, 不含 i 本身
        // 而 start = (i - p[i]) / 2, len = p[i] 恰好就是该回文串在 s 中的对应位置
        int C = 0, R = 0;
        int len = 0, start = 0;
        for (int i = 1; i < snew.size()-1; ++i) { 
            if (i < R) {
                p[i] = min(p[2*C-i], R-i);
            }
            while ( snew[i-p[i]-1] == snew[i+p[i]+1] ) p[i]++;
            if (i + p[i] > R) {
                R = i + p[i];
                C = i;
            }
            if (p[i] > len) {
                len = p[i];
                start = (i - len) / 2;
            }
        }

        return s.substr(start, len);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestPalindrome("ccc") << endl;
    cout << sol.longestPalindrome("") << endl;
    cout << sol.longestPalindrome("babad") << endl;
    cout << sol.longestPalindrome("cbbd") << endl;

    return 0;
}
