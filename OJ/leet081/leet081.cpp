/*
leet081


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

bool bisearch(const vector<int>& v, int x, int lft, int rht) {
    auto R = rht;
    while (lft < rht) {
        auto mid = (lft + rht) / 2;
        if (v[mid] >= x) rht = mid;
        else lft = mid + 1;
    }
    return lft < R and v[lft] == x;
}

int partition(const vector<int>& v, int x0, int rht) {
    int lft = 0;
    while (lft < rht) {
        auto mid = (lft + rht) / 2;
        if (v[mid] < x0) rht = mid;
        else lft = mid + 1;
    }
    return lft;
}



class Solution {
public:

    bool search(const vector<int>& v, int x) {
        // 最坏 O(N), 一般 O(log N)
        if (x == v[0]) return true;
        int rht = v.size();
        while (rht > 1 && v[rht-1] == v[0]) rht--;

        int p = partition(v, v[0], rht); // 找到断点位置[0, p) 上升, [p, end) 上升

        return x > v[0] 
                ? bisearch(v, x, 0, p) 
                : bisearch(v, x, p, rht);
    }
};

int main(int argc, char const *argv[])
{

    Solution sol; 
    cout << boolalpha;
    cout << sol.search({1}, 1) << endl;
    cout << sol.search({1, 3}, 0) << endl;
    cout << sol.search({1, 0, 1, 1, 1}, 1) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 2) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 0) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 3) << endl;

    return 0;
}
