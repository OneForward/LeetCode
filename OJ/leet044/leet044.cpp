/*
leet044


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // 612ms, 7MB
        size_t n = s.size(), m = p.size();
        vector<bool> f(m+1, false), fp(m+1, false);
        f[0] = true; 
        for (size_t j = 1; j <= m; ++j) if (p[j-1] == '*') f[j] = true; else break;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 0; j <= m; ++j) fp[j] = f[j]; f[0] = false;
            for (size_t j = 1; j <= m; ++j) {
                if (p[j-1] == '*') f[j] = f[j-1] | fp[j-1] | fp[j];
                else if (p[j-1] == '?' || p[j-1] == s[i-1]) f[j] = fp[j-1];
                else f[j] = false;
            }   
        }
        return f[m];
    }
    bool isMatch2(string s, string p) {
        // 304ms, 11.3MB
        size_t n = s.size(), m = p.size();
        vector<vector<bool>> f(n+1, vector<bool>(m+1, false));
        f[0][0] = true;
        for (size_t j = 1; j <= m; ++j) if (p[j-1] == '*') f[0][j] = f[0][j-1];
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (p[j-1] == '*') f[i][j] = f[i-1][j-1] | f[i][j-1] | f[i-1][j];
                else if (p[j-1] == '?' || p[j-1] == s[i-1]) f[i][j] = f[i-1][j-1];
            }
        }
        return f[n][m];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isMatch("aa", "a") << endl;
    cout << boolalpha << sol.isMatch("cb", "?a") << endl;
    cout << boolalpha << sol.isMatch("", "") << endl;
    cout << boolalpha << sol.isMatch("cb", "?*") << endl;
    cout << boolalpha << sol.isMatch("aaaa", "*") << endl;
    cout << boolalpha << sol.isMatch("aa", "*") << endl;
    cout << boolalpha << sol.isMatch("a", "*") << endl;
    cout << boolalpha << sol.isMatch("", "*") << endl;
    cout << boolalpha << sol.isMatch("adceb", "*a*b") << endl;
    cout << boolalpha << sol.isMatch("acdcb", "a*c?b") << endl;
    return 0;
}
