/*
leet1277


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
    int countSquares(const  vector<vector<int>>& M) {
        auto m = M.size(), n = M[0].size();
        auto cnt = 0;

        vector<vector<int>> f(m+1, vector<int>(n+1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j]) {
                    f[i+1][j+1] = min(f[i][j+1], min(f[i+1][j], f[i][j])) + 1;
                    cnt += f[i+1][j+1];
                }
            }
        }
        
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countSquares({
                {0,1,1,1},
                {1,1,1,1},
                {0,1,1,1}
                }) << endl;
    return 0;
}
