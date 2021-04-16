/*
leet057


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
    vector<vector<int>> insert(vector<vector<int>> intervals, const vector<int>& newInterval) {
        // O(N), 20ms
        intervals.push_back(newInterval);
        for (int i = intervals.size()-1; i >= 1; --i) {
            if (intervals[i][0] < intervals[i-1][0]) swap(intervals[i], intervals[i-1]);
        }

        vector<vector<int>> ans = { intervals[0] };
        for (const auto& vi: intervals) {
            auto& last = ans.back();
            if (last[1] >= vi[0]) last[1] = max(vi[1], last[1]);
            else ans.push_back(vi);
        }
        return ans;
    }
    vector<vector<int>> insert2(vector<vector<int>> Vs, const vector<int>& v) {
        // O(N)
        vector<vector<int>> ans;
        auto p = Vs.begin();
        int lft = v[0], rht = v[1];

        while (p != Vs.end() and (*p)[1] < lft) ans.push_back(*p), ++p;
        while (p != Vs.end() and (*p)[0] <= rht) {
            lft = min(lft, (*p)[0]); rht = max(rht, (*p)[1]); ++p;
        }
        ans.push_back({lft, rht});

        while (p != Vs.end()) ans.push_back(*p), ++p;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.insert({ {1,3},{6,9},  }, {2, 5}) << endl;
    cout << sol.insert({ {1,2},{3,5},{6,7},{8,10},{12,16} }, {4, 8}) << endl;
    cout << sol.insert({  }, {5, 7}) << endl;
    cout << sol.insert({ {1,5} }, {2,3}) << endl;
    cout << sol.insert({ {1,5} }, {2,7}) << endl;
    return 0;
}
