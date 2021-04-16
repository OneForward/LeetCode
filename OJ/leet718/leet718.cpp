/*
leet718


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
    int findLength(const vector<int>& A, const vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; ++i) { 
            for (int j = 1; j <= m; ++j) { 
                if (A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1] + 1;
            }
        }
        int maxVal = 0;
        for (const auto& row: f) {
            for (const auto& ri: row) maxVal = max(maxVal, ri);
        }
        return maxVal;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findLength( {1,2,3,2,1}, {3,2,1,4,7} ) << endl;
    return 0;
}
