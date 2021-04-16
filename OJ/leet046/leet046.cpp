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
    bool next_permutation(vector<int>& v) {
        size_t N = v.size(), p1 = N - 1, p2 =  N - 1;
        while (p1 > 0 && v[p1-1] > v[p1] ) p1--;
        if (p1 == 0) return false;

        while (v[p2] < v[p1-1]) p2--;
        swap(v[p1-1], v[p2]);
        for (int i = 0; i < (N - p1)/2; ++i) 
            swap(v[p1+i], v[N-i-1]);
        return true;
    }
    vector<vector<int>> permute(vector<int>& v) {
        // 0ms
        if (v.empty()) return {};
        
        sort(v.begin(), v.end());
        vector<vector<int>> ans = {v};
        while (next_permutation(v)) ans.push_back(v);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector v = {0, -1, 1};

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
