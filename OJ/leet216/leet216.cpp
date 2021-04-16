/*
leet216


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

class Solution1 {
public:
    vector<vector<int>> ans;
    void dfs(int start, int k, int target, vector<int>& prev ) {
        // 带有剪枝
        if (k == 0) {
            if (target == 0) ans.push_back(prev);
            return;
        }
        
        if (2 * target > k * (19 - k)) return;
        for (int i=start; i <= 10-k; ++i) {
            if (i >  target / k - (k-1) / 2 + 1) break;
            prev.push_back(i);
            dfs(i+1, k-1, target-i, prev);
            prev.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        ans.clear(); vector<int> prev;
        dfs(1, k, target, prev);
        return ans;
    }
};

class Solution {
public:
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans; vector<int> prev; 

        function<void(int, int, int)> dfs = [&](int start, int k, int target) {
            if (k == 0) {
                if (target == 0) ans.push_back(prev);
                return;
            }
            
            for (int i=start; i <= 10-k; ++i) {
                prev.push_back(i);
                dfs(i+1, k-1, target-i);
                prev.pop_back();
            }
        };
        
        dfs(1, k, target);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.combinationSum3(3, 7) << endl;
    // cout << sol.combinationSum3(3, 9) << endl;
    cout << sol.combinationSum3(9, 45) << endl;
    return 0;
}
