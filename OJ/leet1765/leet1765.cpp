/*
leet1765


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
    vector<vector<int>> highestPeak1(const vector<vector<int>>& isWater) {
        const int DIR[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        auto R = isWater.size(), C = isWater[0].size();
        auto ans = vector<vector<int>>(R, vector<int>(C));
        queue<pair<int, int>> Q; 
        for (size_t i = 0; i < R; ++i) { 
            for (size_t j = 0; j < C; ++j) { 
                if (isWater[i][j]) Q.push({i, j}), ans[i][j] = 0;
                else ans[i][j] = -1;
            }
        } Q.push({-1, -1});

        int height = 1;
        while (Q.size() > 1) {
            auto [r0, c0] = Q.front(); Q.pop();
            if (r0 == -1 and c0 == -1) {
                height++; Q.push({-1, -1}); continue;
            }
            for (const auto& [dr, dc]: DIR) {
                auto r = r0 + dr, c = c0 + dc;
                if (r < 0 or r >= R or c < 0 or c >= C or ans[r][c] >= 0) continue;
                Q.push({r,c}); ans[r][c] = height;
            }
        }
        return ans;
    }
    vector<vector<int>> highestPeak(vector<vector<int>> isWater) {
        const int DIR[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        auto R = isWater.size(), C = isWater[0].size();
        vector<vector<int>> ans(R, vector<int>(C));
        queue<pair<int, int>> Q; 
        for (size_t i = 0; i < R; ++i) { 
            for (size_t j = 0; j < C; ++j) { 
                if (isWater[i][j]) Q.push({i, j});
            }
        } 
        
        while (Q.size()) {
            auto [r0, c0] = Q.front(); Q.pop();
            for (const auto& [dr, dc]: DIR) {
                auto r = r0 + dr, c = c0 + dc;
                if (r < 0 or r >= R or c < 0 or c >= C or isWater[r][c]) continue;
                Q.push({r,c}); ans[r][c] = ans[r0][c0] + 1; isWater[r][c] = 1;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.highestPeak({{0,1},{0,0}}) << endl;
    cout << sol.highestPeak({{0,0,1},{1,0,0},{0,0,0}}) << endl;
    return 0;
}
