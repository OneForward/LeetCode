/*
leet406


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
    vector<vector<int>> reconstructQueue(vector<vector<int>> people) {
        auto cmp = [&](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0] or (v1[0] == v2[0] and v1[1] > v2[1]);
        };
        sort(people.rbegin(), people.rend(), cmp);
        
        vector<vector<int>> ans; ans.reserve(people.size());
        for (auto&& v: people) {
            ans.insert(ans.begin() + v[1], v);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.reconstructQueue({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}) << endl;
    return 0;
}
