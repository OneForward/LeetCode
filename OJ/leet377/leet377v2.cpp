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
    int combinationSum4(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        vector<int> f(target+1); f[0] = 1;
        for (int t = 0; t <= target; t++)
        {
            for (auto &&x : nums)
            {
                if (x > t) break;
                else f[t] += f[t - x] ;
            }
        }
        
        return f[target];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.combinationSum4( {1,2,3}, 4 ) << endl;
    return 0;
}
