/*
leet188


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
    int greedy(const vector<int>& prices) {
        // k = INFINITE
        int ans = 0, start = 0;
        while (start < prices.size()) {
            int i = start;
            while (i + 1 < prices.size() && prices[i+1] > prices[i]) ++i;
            ans += prices[i] - prices[start]; start = i + 1;
        }
        return ans;
    }

    int maxProfit(int k, const vector<int>& prices) {
        // 12ms
        if (k == 0) return 0;
        if (k > prices.size()/2)  return greedy(prices);
        
        vector<int> buy(k, INT_MIN), sell(k);
        for (const auto p:prices) {
            buy[0] = max(buy[0], -p);
            sell[0] = max(sell[0], buy[0] + p );
            for (int i = 1; i < k; ++i) {
                buy[i] = max(buy[i], sell[i-1]-p);
                sell[i] = max(sell[i], buy[i] + p );
            }
        }
        return sell[k-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit(2, {2, 4, 1}) << endl;
    cout << sol.maxProfit(2, {3,2,6,5,0,3}) << endl;
    return 0;
}
