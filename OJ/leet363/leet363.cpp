/*
leet363


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int maxSumSubmatrix(const vector<vector<int>>& M, int k) {
        // O(R^2 C log C)
        int R = M.size(), C = M[0].size();
        
        vector f(C, 0); int ans = INT_MIN;
        for (int r1 = 0; r1 < R; r1++)
        {
            fill(f.begin(), f.end(), 0);
            for (int r2 = r1; r2 < R; r2++)
            {

                for (int c = 0; c < C; c++)
                {
                    f[c] += M[r2][c];
                }
                
                set S{0}; int sum = 0;
                for (auto&& x: f) {
                    sum += x;
                    auto lft = S.lower_bound(sum - k);
                    if (lft != S.end()) ans = max(sum - *lft, ans);
                    S.insert(sum);
                }
                if (ans == k) break;
            }
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSumSubmatrix({{2,2,-1}}, 2) << endl;
    cout << sol.maxSumSubmatrix({{1,0,1},{0,-2,3}}, 3) << endl;
    return 0;
}
