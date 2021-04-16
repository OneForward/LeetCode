/*
leet035


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
    if (x <= v[0]) return 0;

    int lft = 0, rht = v.size(), mid;
    while (lft < rht) {
        mid = lft + (rht - lft) / 2;
        if (v[mid] < x) lft = mid+1;
        else  rht = mid;
    }
    return lft;
}

class Solution {
public:
    int searchInsert(vector<int>& v, int x) {
        // 4ms
        return bisearch_lft(v, x);
    }
};

int main(int argc, char const *argv[])
{
    vector v = {1, 3, 5, 6}; int x= 1;
    for (auto vi: v) cout << vi << ", "; cout << endl;
    cout << "lft = " << bisearch_lft(v, x) << endl;
    // cout << "rht = " << bisearch_rht(v, 8) << endl;
    // Solution sol; int x = 3;

    return 0;
}
