/*
leet1745


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        // O(N^2)
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t L = 0; L <= i; L++)
            {
                if (s[i+L] == s[i-L]) f[i-L][i+L] = true;
                else break;
            }
            for (size_t L = 0; L <= i; L++)
            {
                if (s[i+L+1] == s[i-L]) f[i-L][i+L+1] = true;
                else break;
            }
        }
        
        for (size_t i1 = 0; i1 < n; i1++)
        {
            if (not f[0][i1]) continue;
            for (size_t i3 = i1 + 2; i3 < n; i3++)
            {
                if (not f[i3][n-1]) continue;

                if (f[i1+1][i3-1]) return true;
            }
            
        }
        return false;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.checkPartitioning("abcbdd") << endl;
    cout << sol.checkPartitioning("bcbddxy") << endl;
    return 0;
}
