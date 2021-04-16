/*
leet056


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        // 20ms, 合并区间，排序， O(N log N)
        auto cmp = [&](const vector<int>& lft, const vector<int>& rht) {
            return lft[0] < rht[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ans = {intervals[0]};
        for (const auto& v: intervals) {
            auto& back = ans.back();
            if (back[1] >= v[0]) back[1] = max(back[1], v[1]);
            else ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.merge({{2,6},{8,10},{1,3},{15,18}}) << endl;
    cout << sol.merge({{1, 4}, {4, 5}}) << endl;
    return 0;
}
