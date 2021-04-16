/*
leet1353


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
    int maxEvents(vector<vector<int>> events) {
        auto cmp = [&] (const vector<int>& lft, const vector<int>& rht) {
            return lft[0] < rht[0] or (lft[0] == rht[0] and lft[1] < rht[1]);
        };
        sort(events.begin(), events.end(), cmp);

        int ans = 0; int prev = 0;
        for (const auto& v: events) {
            if (v[0] > prev) ans++;
            prev = max(v[1], prev);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxEvents({{1,2},{2,3},{3,4}}) << endl;
    cout << sol.maxEvents({{1,2},{2,3},{3,4},{1,2}}) << endl;
    cout << sol.maxEvents({{1,4},{4,4},{2,2},{3,4},{1,1}}) << endl;
    cout << sol.maxEvents({{1,10000}}) << endl;
    cout << sol.maxEvents({{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},}) << endl;
    return 0;
}
