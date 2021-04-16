/*
leet040


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;


class Solution {
    vector<int> candidates;
    vector<vector<int>> ans; 
    vector<int> path;
public:
    void dfs(int start, int target) {
        // 8ms
        if (target == 0){ ans.push_back(path);  return; }
        int i = start;
        while ( i < candidates.size() && target - candidates[i] >= 0 ) {
            path.push_back(candidates[i]);
            dfs(i+1, target-candidates[i]);
            path.pop_back(); ++i;
            while (i < candidates.size() && candidates[i] == candidates[i-1]) ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());
        this->candidates = candidates;
        dfs(0, target);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector candidates = {2,5,2,1,2};
    int target = 5;

    Solution sol;
    auto ans = sol.combinationSum2(candidates, target);
    for (auto v: ans) {
        for (auto vi: v) {
            cout << vi << ", "; 
        }
        cout << endl;
    }

    return 0;
}
