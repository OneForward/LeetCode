/*
leet986


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
    vector<vector<int>> intervalIntersection(const vector<vector<int>>& V1, const vector<vector<int>>& V2) {
        // O(M+N)
        vector<vector<int>> ans;
        auto p1 = V1.begin(), p2 = V2.begin();
        while (p1 != V1.end() and p2 != V2.end()) {
            auto lo = max((*p1)[0], (*p2)[0]);
            auto hi = min((*p1)[1], (*p2)[1]);
            if (lo <= hi) ans.push_back({lo, hi});
            if ((*p1)[1] < (*p2)[1]) p1++;
            else p2++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.intervalIntersection({{0,2},{5,10},{13,23},{24,25}}, {{1,5},{8,12},{15,24},{25,26}}) << endl;
    return 0;
}
