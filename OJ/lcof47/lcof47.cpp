/*
lcof47


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& M) {
        int f[200]{};
        int R = M.size(), C = M[0].size();
        for (int c = 1; c < C; ++c) f[c] = f[c-1] + M[0][c-1];
        for (int r = 1; r < R; ++r) {
            f[0] += M[r-1][0];
            for (int c = 1; c < C; ++c) {
                f[c] = max(f[c-1] + M[r][c-1], f[c] + M[r-1][c]);
            }
        }
        return f[C-1] + M[R-1][C-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
