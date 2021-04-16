/*
leet046


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
public:
    vector<vector<int>> permute(vector<int>& v, int start = 0) {
        // 0ms
        if (start == v.size()) return {{}};
        
        auto no = permute(v, start+1);
        auto x = v[start];
        vector<vector<int>> ans;
        
        for (const auto& vi: no) {
            for (size_t i = 0; i <= vi.size(); i++)
            {
                auto v = vi;
                v.insert(v.begin() + i, x);
                ans.push_back(v);
            }
        }
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    vector v = {1,2,3};

    Solution sol;

    auto ans = sol.permute(v);
    for (auto row: ans) {
        for (auto ri: row) {
            cout << ri << ", ";
        }
        cout << endl;
    }
    return 0;
}
