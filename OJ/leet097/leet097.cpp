/*
leet097

动态规划
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 4ms
        size_t n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        f[0][0] = true;
        for (size_t i = 1; i <= n; ++i) {
            if (s1[i-1] == s3[i-1]) f[i][0] = true;
            else break;
        }
        for (size_t j = 1; j <= m; ++j) {
            if (s2[j-1] == s3[j-1]) f[0][j] = true;
            else break;
        }
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if ((s3[i+j-1] == s1[i-1] && f[i-1][j]) || 
                    (s3[i+j-1] == s2[j-1] && f[i][j-1])) 
                    f[i][j] = true;
            }
        }
        return f[n][m];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isInterleave( "a",  "",  "a") << endl;
    cout << boolalpha << sol.isInterleave( "aabcc",  "dbbca",  "aadbbcbcac") << endl;
    cout << boolalpha << sol.isInterleave( "aabcc",  "dbbca",  "aadbbbaccc") << endl;
    return 0;
}
