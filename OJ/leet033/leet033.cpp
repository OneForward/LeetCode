/*
leet033


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

int bisearch(vector<int>& v, int x, int lft, int rht) {
    int mid;
    while (lft < rht) {
        mid = lft + (rht - lft) / 2;
        if (v[mid] < x) lft = mid+1;
        else if (v[mid] > x) rht = mid;
        else return mid;
    }
    return -1;
}

int bisearch2(vector<int>& v, int v0) {
    int lft = 0, rht = v.size(), mid;
    while (lft < rht-1) {
        mid = lft + (rht - lft) / 2;
        if (v[mid-1] > v[mid]) return mid;
        if (v[mid] > v0) lft = mid;
        else  rht = mid;
    }
    return rht;
}



class Solution {
public:

    int search(vector<int>& v, int x) {
        // 4ms
        if (v.empty()) return -1;

        int p = bisearch2(v, v[0]); // 找到断点位置[0, p) 上升, [p, end) 上升

        return x >= v[0] 
                ? bisearch(v, x, 0, p) 
                : bisearch(v, x, p, v.size());
    }
};

int main(int argc, char const *argv[])
{
    // vector v = {4, 5, 6, 7, 0, 1, 2};
    vector v = {3};
    // vector v = {1, 2, 3, 4, 5};
    // sort(v.begin(), v.end());
    for (auto vi: v) cout << vi << ", "; cout << endl;

    Solution sol; int x = 3;
    cout << "ans = " << sol.search(v, x) << endl;

    return 0;
}
