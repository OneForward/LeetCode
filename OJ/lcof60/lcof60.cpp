/*
lcof60


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
    vector<double> dicesProbability(int N) {
        int f[12][70]{{}, {0, 1,1,1,1,1,1}};
        for (int n = 2; n <= N; ++n) {
            for (int pts = n; pts <= 6 * n; ++pts) {
                for (int k = max(pts-6, 1); k < pts; ++k) f[n][pts] += f[n-1][k];
            }
        }
        auto sum = 0;
        for (int pts = N; pts <= 6 * N; ++pts) sum += f[N][pts];

        vector<double> ans; ans.reserve(5 * N + 1);
        for (int pts = N; pts <= 6 * N; ++pts) ans.push_back( f[N][pts] / (double)sum );
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.dicesProbability(1) << endl;
    cout << sol.dicesProbability(2) << endl;
    return 0;
}
