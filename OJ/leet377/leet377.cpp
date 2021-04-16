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
        function<void(int)> f = [&](int target) {
            if (target == 0) cnt++;
            for (auto &&x : nums)
            {
                if (x > target) break;
                f(target - x);
            }
        };
        f(target);
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.combinationSum4( {1,2,3}, 4 ) << endl;
    return 0;
}
