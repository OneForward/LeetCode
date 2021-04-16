/*
leet077

递归，回溯，组合
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // 52ms
        if (k == 1) {
            vector<vector<int>> ans;
            for (int i = 1; i <= n; ++i) ans.push_back({i});
            return ans;
        }
        if (n == k) {
            vector<int> v(k);
            for (int i = 1; i <= n; ++ i) v[i-1] = i;
            return {v};
        }
        vector<vector<int>> yes = combine(n-1, k-1), no = combine(n-1, k);
        for (auto& vi: yes) vi.push_back(n);
        yes.insert(yes.end(), no.begin(), no.end());
        return yes;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto ans = sol.combine(10, 3);
    for (auto row: ans) {
        for (auto ri: row) cout << ri << ", "; cout << endl;
    }
    return 0;
}
