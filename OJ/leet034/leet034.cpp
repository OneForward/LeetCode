/*
leet034


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

int bisearch_lft(vector<int>& v, int x) {
    if (v.empty()) return -1;
    if (x > v[v.size()-1]) return -1;
    int lft = 0, rht = v.size(), mid;
    while (lft < rht) {
        mid = lft + (rht - lft) / 2;
        if (v[mid] < x) lft = mid+1;
        else  rht = mid;
    }
    return  v[lft] == x ? lft : -1;
}


int bisearch_rht(vector<int>& v, int x) {
    if (v.empty()) return -1;
    if (x < v[0]) return -1;
    int lft = 0, rht = v.size(), mid;
    while (lft < rht) {
        mid = lft + (rht - lft) / 2;
        if (v[mid] <= x) lft = mid+1;
        else  rht = mid;
    }
    return  v[lft-1] == x ? lft-1 : -1;
}


class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
        // 12ms, 60%
        return {bisearch_lft(v, x) , bisearch_rht(v, x) };
    }
};

int main(int argc, char const *argv[])
{
    // vector v = {5, 5, 5, 7, 7, 8, 8, 10};
    vector v = {2, 2};
    // vector v = {1, 2, 3, 4, 5};
    // sort(v.begin(), v.end());
    for (auto vi: v) cout << vi << ", "; cout << endl;
    // cout << "lft = " << bisearch_lft(v, 8) << endl;
    // cout << "rht = " << bisearch_rht(v, 8) << endl;
    Solution sol; int x = 3;
    vector ans = sol.searchRange(v, x);
    cout << "ans = " << ans[0] << ", " << ans[1] << endl;

    return 0;
}
