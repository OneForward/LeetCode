/*
leet377


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
    int combinationSum4(const vector<int>& A, int target) {
        // 完全背包, 有序
        unsigned long long f[1005]{1};
        for (int t = 0; t <= target; ++t) {
            for (auto&& x: A) {
                if (t >= x) f[t] += f[t - x];
            }
        }
        return f[target];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.combinationSum4( {1,2,3}, 4 ) << endl;
    cout << sol.combinationSum4( {3,2,1}, 4 ) << endl;
    cout << sol.combinationSum4( {1,3,2}, 4 ) << endl;
    cout << sol.combinationSum4( {3,1,2}, 4 ) << endl;
    cout << sol.combinationSum4( {2,3,1}, 4 ) << endl;
    cout << sol.combinationSum4( {2,1,3}, 4 ) << endl;
    return 0;
}
