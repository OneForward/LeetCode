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
public:
    vector<vector<int>> dfs(vector<int>& candidates, int start, int target) {
        // cnt += 1;
        if (target == 0) return {{}};
        if (start == candidates.size() ) return {};
        vector<vector<int>> ans{}; int cnt = 0;
        while (target >= 0) {
            vector<vector<int>> v = dfs(candidates, start+1, target);
            for (auto& vi: v) for (int i = 0; i < cnt; ++i)  vi.push_back(candidates[start]);
            ans.insert(ans.end(), v.begin(), v.end());
            target -= candidates[start]; cnt++;
        }
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        return dfs(candidates, 0, target);
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
