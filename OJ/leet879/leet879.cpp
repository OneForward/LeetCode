/*
leet879


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int profitableSchemes(int N, int P, const vector<int>& group, const vector<int>& profit) {
        int f[101][101]{};
        const int MOD = 1e9 + 7;
        for (int n = 0; n < 101; n++) f[n][0] = 1;
        
        int len = group.size();
        for (int i = 0; i < len; ++i) 
        { 
            auto gi = group[i], pi = profit[i];
            for (int n = N; n >= gi; n--)
            {
                for (int p = P; p >= 0; p--)
                {
                    f[n][p] += f[n-gi][max(0, p - pi)];
                    f[n][p] %= MOD;
                }
            }
        }
        
        return f[N][P];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.profitableSchemes(5, 3, {2,2}, {2,3}) << endl;
    cout << sol.profitableSchemes(10, 5, {2,3,5}, {6,7,8}) << endl;
    return 0;
}
