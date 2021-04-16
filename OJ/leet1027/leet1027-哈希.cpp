/*
leet1027


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
    int longestArithSeqLength(const vector<int>& A) {
        
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        vector<int> M(10005, -1);

        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int target = 2 * A[i] - A[j];
                if (target >= 0 and M[target] >= 0) dp[i][j] = dp[M[target]][i] + 1;
                ans = max(ans, dp[i][j]);
            }
            M[A[i]] = i;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestArithSeqLength({1,3,2,4}) << endl;
    cout << sol.longestArithSeqLength({1,2,3}) << endl;
    cout << sol.longestArithSeqLength({3,6,9,12}) << endl;
    cout << sol.longestArithSeqLength({9,4,7,2,10}) << endl;
    cout << sol.longestArithSeqLength({20,1,15,3,10,5,8}) << endl;
    cout << sol.longestArithSeqLength({83,20,17,43,52,78,68,45}) << endl;
    return 0;
}
