/*
leet121


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution1 {
public:
    int ans;
    void merge(vector<int>& v, int lft, int rht) {
        if (lft >= rht-1) return;
        int mid = (lft + rht) / 2;
        merge(v, lft, mid);
        merge(v, mid, rht);

        ans = max(ans, v[rht-1] - v[lft] );

        vector<int> vtmp = v;
        int p = lft, p1 = lft, p2 = mid;
        while (p1 < mid && p2 < rht) {
            if (v[p1] < v[p2]) vtmp[p++] = v[p1++];
            else vtmp[p++] = v[p2++];
        }
        while (p1 < mid) vtmp[p++] = v[p1++];
        while (p2 < rht) vtmp[p++] = v[p2++];
        v = vtmp;
    }
    int maxProfit(const vector<int>& prices) {
        // 584ms, 338MB
        vector<int> v = prices; ans = 0;
        merge(v, 0, v.size());
        return ans;
    }
};

class Solution {
public:
    
    int maxProfit(const vector<int>& prices) {
        // 4ms, 13MB
        int ans = 0, cur_min = INT_MAX;
        for (auto pi: prices) {
            cur_min = min(pi, cur_min);
            ans = max(ans, pi - cur_min);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit({7,1,5,3,6,4}) << endl;
    cout << sol.maxProfit({7,6,4,3,1}) << endl;
    return 0;
}
