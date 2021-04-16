/*
leet078

递归，回溯
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v, int start) {
        // 4ms
        if (start == v.size()) return {{}};
        auto no = subsets(v, start+1);
        auto yes = no; 
        for (auto& vi: yes) vi.push_back(v[start]);
        yes.insert(yes.end(), no.begin(), no.end());
        return yes;
    }
    vector<vector<int>> subsets(vector<int>& v) {
        return subsets(v, 0);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v  = {1, 2, 3};
    Solution sol;   
    auto ans = sol.subsets(v);
    for (auto row: ans) {
        for (auto ri: row) cout << ri << ", "; cout << endl;
    }
    return 0;
}
