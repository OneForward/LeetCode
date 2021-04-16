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
        // 880ms, Time O(N^2) Space O(N*range(A))
        int n = A.size(); int maxVal = 0;
        vector<vector<int>> f(n, vector<int>(20005));
        
        for (int j = 1; j < n; ++j) { 
            for (int k = 0; k < j; ++k) {
                auto d = A[j] - A[k] + 10000;
                f[j][d] = 1;
            }
        }
        for (int i = 2; i < n; ++i) { 
            for (int j = 1; j < i; ++j) {
                auto d = A[i] - A[j] + 10000;
                f[i][d] = f[j][d] + 1;
                maxVal = max(maxVal, f[i][d]);
            }
        }
        return maxVal + 1;
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
