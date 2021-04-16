/*
leet122


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

    int maxProfit(const vector<int>& prices) {
        // 4ms, O(N)
        // 原理：对于任意的 A[i] > A[i+1], 假若在 A[i] 时买入，都不如在 A[i+1] 时买入
        int ans = 0, start = 0;
        while (start < prices.size()) {
            int i = start;
            while (i + 1 < prices.size() && prices[i+1] > prices[i]) ++i;
            ans += prices[i] - prices[start]; start = i + 1;
        }
        return ans;
    } 
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit({7,1,5,3,6,4}) << endl;
    cout << sol.maxProfit({1,2,3,4,5}) << endl;
    cout << sol.maxProfit({1,}) << endl;
    cout << sol.maxProfit({1,2}) << endl;
    cout << sol.maxProfit({7,6,4,3,1}) << endl;
    return 0;
}
