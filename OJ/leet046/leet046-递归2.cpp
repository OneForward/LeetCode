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
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans = {v}; 

        function<void(int)> _permute = [&](int rht) {
            if (rht == v.size()) return;
            int len = ans.size();
            while (len--) {
                auto vi = ans[len];
                for (size_t lft = 0; lft < rht; lft++)
                {
                    swap(vi[lft], vi[rht]);
                    ans.push_back(vi);
                    swap(vi[lft], vi[rht]);
                }
            }
            _permute(rht + 1);
        };

        _permute(1);

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
