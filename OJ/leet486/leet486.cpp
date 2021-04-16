/*
leet486


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
    bool PredictTheWinner(const vector<int>& A) {
        int n = A.size();
        vector<int> g = {0}; g.reserve(n+1);
        for (auto&& x: A) g.push_back(g.back() + x);

        vector<vector<int>> f(n, vector<int>(n));
        
        for (int i = 0; i < n; ++i) f[i][i] = A[i];
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                auto sum1 = g[i+len+1] - g[i+1];
                auto sum2 = g[i+len] - g[i];
                f[i][i+len] = max(A[i] - f[i+1][i+len] + sum1, A[i+len] - f[i][i+len-1] + sum2);
            }
        }
        // cout << g << endl;
        // cout << f << endl;
        return f[0][n-1] * 2 >= g.back();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    // cout << sol.PredictTheWinner({1,5,2,4,6}) << endl;
    // cout << sol.PredictTheWinner({100, 100, 100}) << endl;
    // cout << sol.PredictTheWinner({1, 5, 233, 7}) << endl;
    // cout << sol.PredictTheWinner({1, 5, 2}) << endl;
    cout << sol.PredictTheWinner({1, 3, 1}) << endl;
    cout << sol.PredictTheWinner({1, 2}) << endl;
    return 0;
}
