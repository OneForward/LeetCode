#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // 动态规划
        bool f[21][31]{true}; 
        int N = s.size(), M = p.size();
        for (int j = 0; j < M; ++j) {
            if (p[j] == '*' or (j < M-1 and p[j+1] == '*'))  f[0][j+1] = f[0][j];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (j < M-1 and p[j+1] == '*')  {
                    f[i+1][j+1] |= f[i+1][j];
                    if (p[j] == '.' or p[j] == s[i]) f[i+1][j+1] |= (f[i][j] or f[i][j+1]);
                }
                else if (p[j] == '*') f[i+1][j+1] =  f[i+1][j];
                else f[i+1][j+1] = f[i][j] and (s[i] == p[j] or p[j] == '.');
            }
        }
        return f[N][M];
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution solution;
    cout << solution.isMatch("c", "c*a*") << endl;
    cout << solution.isMatch(
        "ac",
        "a*c*a*b*.*aa*c*a*a*"
    ) 
    << endl;
    cout << solution.isMatch(
        "cbaacacaaccbaabcb",
        "c*b*b*.*ac*.*bc*a*"
    ) 
    << endl;
    cout << solution.isMatch(
        "aabcbcbcaccbcaabc",
        ".*a*aa*.*b*.c*.*a*"
    ) 
    << endl;
    cout << solution.isMatch("bbbba", ".*a*a") << endl;
    cout << solution.isMatch("", "c*c*") << endl;
    cout << solution.isMatch("", "") << endl;
    cout << solution.isMatch("", ".*.*.*") << endl;
    cout << solution.isMatch("adsfj", ".*.*.*") << endl;
    cout << solution.isMatch("a", ".*.*.*.") << endl;
    
    cout << solution.isMatch("a", "ab*") << endl;
    cout << solution.isMatch("aaaaa", "a*a") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aaa") << endl;
    return 0;
}
