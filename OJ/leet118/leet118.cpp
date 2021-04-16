/*
leet118


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 0ms
        if (numRows == 0) return {};
        vector<vector<int>> ans = {{1}};
        vector<int> v; int prev;
        while (--numRows) {
            v = {}; prev = 0;
            for (const auto& vi: ans.back()) {
                v.push_back(prev + vi);
                prev = vi;
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto ans = sol.generate(5);
    
    for (auto row: ans) {
        for (auto ri: row) cout << ri << ", "; cout << endl;
    }
    return 0;
}
