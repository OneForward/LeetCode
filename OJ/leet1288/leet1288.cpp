/*
leet1288


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
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> intervals) {
        auto cmp = [&](const vector<int>& lft, const vector<int>& rht) {
            return lft[0] < rht[0] or (lft[0] == rht[0] and lft[1] > rht[1]); // v[0] 递增, 相同时 v[1] 递减
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = intervals.size(), curmax = 0;
        for (const auto& v: intervals) {
            if (curmax >= v[1]) ans--;
            else curmax = v[1];
        }
        return ans;
    }
}; 


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeCoveredIntervals({{1,4}, {3,6}, {2,8}}) << endl;
    cout << sol.removeCoveredIntervals({{1,2}, {1,4}, {3,4}}) << endl;
    return 0;
}
