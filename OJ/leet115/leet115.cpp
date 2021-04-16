/*
leet115


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long>> f(m+1, vector<long>(n+1)); 
        for (int i = 0; i < n; i++) f[0][i] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                f[i+1][j+1] = f[i+1][j];
                if (t[i] == s[j]) f[i+1][j+1] += f[i][j];
            }
            
        }
        return f[m][n];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numDistinct("rabbbit",  "rabbit") << endl;
    cout << sol.numDistinct("babgbag",   "bag") << endl;
    return 0;
}
