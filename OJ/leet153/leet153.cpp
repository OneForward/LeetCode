/*
leet153


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;




int bisearch(vector<int>& v, int v0) {
    int lft = 0, rht = v.size(), mid;
    while (rht > 1 && v[rht-1] == v0) rht--;
    while (lft < v.size()-1 &&  v[lft+1] == v0) lft++;
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

    int findMin(vector<int>& v) {
        // 12ms
        if (v.empty()) return -1;

        int p = bisearch(v, v[0]); // 找到断点位置[0, p) 上升, [p, end) 上升

        if (p == v.size()) return v[0];
        return min(v[p], v[0]);
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
    cout << "ans = " << sol.findMin(v) << endl;

    return 0;
}
