/*
leet132


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minCut(string s) {
        // O(N^2) 动态规划
        int n  = s.size();
        vector<vector<int>> g(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int L = 0; i-L>=0 and i+L < n; L++)
            {
                if (s[i-L] == s[i+L]) g[i+L].push_back(i-L);
                else break;
            }
            for (int L = 0; i-L>=0 and i+L+1 < n; L++)
            {
                if (s[i-L] == s[i+L+1]) g[i+L+1].push_back(i-L);
                else break;
            }
        }

        vector<int> f(n+1, n); f[0] = 0;
        for (int r = 0; r < n; r++)
        {
            for (auto &&l : g[r])
            {
                f[r+1] = min(f[r+1], f[l] + 1);
            }
        }
        return f[n] - 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minCut("aab") << endl;
    cout << sol.minCut("ab") << endl;
    cout << sol.minCut("a") << endl;
    return 0;
}
