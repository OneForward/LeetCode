/*
leet973


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:

    vector<vector<int>> kClosest(const vector<vector<int>>& points, int K) {
        // O(N), 120ms, 99.42%
        using Pair = pair<int, int>;
        auto n = points.size();
        vector<Pair> v; v.reserve(n);
        for (size_t i = 0; i < n; ++i) { 
            const auto& p = points[i];
            v.push_back({ p[0] * p[0] + p[1] * p[1], i});
        }
        
        nth_element(v.begin(), v.begin() + K, v.end()); // O(N)

        vector<vector<int>> ans; ans.reserve(K);
        for (size_t i = 0; i < K; ++i) { 
            const auto& [_, index] = v[i];
            ans.push_back(points[index]);
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kClosest({{1,3},{-2,2}}, 1) << endl;
    cout << sol.kClosest({{3,3},{5,-1},{-2,4}}, 2) << endl;
    return 0;
}
