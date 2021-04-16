/*
leet039


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

int cnt = 0;
class Solution {
    vector<int> candidates;
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(int start, int target) {
        // 16ms
        if (target == 0){ ans.push_back(path);  return; }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            path.push_back(candidates[i]);
            dfs(i, target-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());
        this->candidates = candidates;
        dfs(0, target);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector candidates = {8, 7, 4, 3};
    int target = 11;

    Solution sol;
    auto ans = sol.combinationSum(candidates, target);
    for (auto v: ans) {
        for (auto vi: v) {
            cout << vi << ", "; 
        }
        cout << endl;
    }
    cout << "cnt = " << cnt << endl;

    return 0;
}
