/*
leet714


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

    int maxProfit1(const vector<int>& A, int fee) {
        // O(N)
        int n = A.size();
        vector<vector<int>> f(n+1, vector<int>(2)); f[0] = {0, INT_MIN};
        for (int i = 0; i < n; ++i)
        {
            const auto& x = A[i];
            f[i+1][0] = max(f[i][0], f[i][1]+x);
            f[i+1][1] = max(f[i][0]-x-fee, f[i][1]);
        }
        // cout << f << endl;
        return f[n][0];
    }

    int maxProfit(const vector<int>& A, int fee) {
        // O(N)
        int buy = INT_MIN, sell = 0;
        for (const auto& x: A)
        {
            buy = max(buy, sell-x-fee);
            sell = max(sell, buy+x);
        }
        return sell;
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit({1, 3, 2, 8, 4, 9}, 2) << endl;
    return 0;
}
