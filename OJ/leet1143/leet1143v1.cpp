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

class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int n = A.size(), m = B.size();
        int f[1001][1001]{};
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < m; ++j) { 
                if (A[i] == B[j]) f[i+1][j+1] = f[i][j] + 1;
                else f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
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
