/*
leet1155


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
    int numRollsToTarget(int dices, int facets, int target) {
        // 4ms
        // 动态规划，注意边界条件
        const long long MOD = 1e9 + 7;
        vector<int> f(target+1), g;
        for (int i = 1; i <= facets and i <= target; ++i) f[i] = 1;
        for (int d = 2; d <= dices; d++)
        {
            g = f;
            auto cursum = 0ll;
            for (int p = 1; p < d; p++) f[p] = 0;
            for (int p = d; p <= target; p++)
            {
                cursum += g[p-1]; 
                if (p > facets + 1) cursum -= g[p-facets-1];
                cursum = (cursum + MOD) % MOD;
                f[p] = cursum;
            }
        }
        return f[target];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.numRollsToTarget(1, 6, 3) << endl;
    // cout << sol.numRollsToTarget(1, 2, 3) << endl;
    // cout << sol.numRollsToTarget(2, 6, 7) << endl;
    cout << sol.numRollsToTarget(3, 6, 7) << endl;
    // cout << sol.numRollsToTarget(2, 5, 10) << endl;
    cout << sol.numRollsToTarget(30, 30, 500) << endl;
    return 0;
}
