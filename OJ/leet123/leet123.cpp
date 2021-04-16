/*
leet123


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



class Solution {
public:

    int maxProfit1(const vector<int>& v) {
        // 16ms, O(N)
        if (v.empty()) return 0;

        vector<int> v1(v.size()), v2(v.size());
        int cur_min = INT_MAX, cur_max = INT_MIN, ans = 0, v1max = 0, v2max = 0;
        for (int i = 0; i < v.size(); ++i) cur_min = min(cur_min, v[i]), v1[i] = v1max = max(v1max, v[i] - cur_min);
        for (int i = v.size()-1; i >= 0; --i) cur_max = max(cur_max, v[i]), v2[i] = v2max = max(v2max, cur_max - v[i]);
        for (int i = 1; i < v.size(); ++i) {
            ans = max( ans, v2[i] + v1[i-1] );
        }
        ans = max(ans, v2[0]);
        return ans;
    } 
    int maxProfit(const vector<int>& v) {
        // 16ms, O(N)
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (auto vi: v) { // assume we have 0 money at first
            buy1 = max(buy1, -vi); // how much we earned so far after 1st bought
            sell1 = max(sell1, buy1 + vi); // how much we earned so far after 1st sold
            buy2 = max(buy2, sell1-vi); // how much we earned so far after 2nd bought
            sell2 = max(sell2, buy2 + vi); // how much we earned so far after 2nd sold
        }
        return sell2;
    } 
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit({3,2,6,5,0,3}) << endl;
    cout << sol.maxProfit({3,3,5,0,0,3,1,4}) << endl;
    cout << sol.maxProfit({1,2,4,2,5,7,2,4,9,0}) << endl;
    cout << sol.maxProfit({7,1,5,3,6,4}) << endl;
    cout << sol.maxProfit({1,2,3,4,5}) << endl;
    cout << sol.maxProfit({1,}) << endl;
    cout << sol.maxProfit({1,2}) << endl;
    cout << sol.maxProfit({7,6,4,3,1}) << endl;
    return 0;
}
