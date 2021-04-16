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



class Solution {
public:
    
    int maxProfit1(const vector<int>& prices) {
        // O(N), 只买一次
        int buy = INT_MIN, sell = 0;
        for (const auto& x: prices) {
            buy = max(buy, -x);
            sell = max(sell, buy+x);
        }
        return sell;
    }

    int maxProfitInf(const vector<int>& prices) {
        // O(N), 买任意次
        int buy = INT_MIN, sell = 0;
        for (const auto& x: prices) {
            buy = max(buy, sell-x);
            sell = max(sell, buy+x);
        }
        return sell;
    }

    int maxProfitInfFee(const vector<int>& prices, int fee) {
        // O(N), 买任意次, 带有手续费
        int buy = INT_MIN, sell = 0;
        for (const auto& x: prices) {
            buy = max(buy, sell-x-fee);
            sell = max(sell, buy+x);
        }
        return sell;
    }

    int maxProfitInfColdStart(const vector<int>& prices) {
        // O(N), 买任意次, 冷冻期1天
        int buy = INT_MIN, sell0 = 0, sell1 = 0;
        for (const auto& x: prices) {
            buy = max(buy, sell1-x);
            sell1 = sell0;
            sell0 = max(sell0, buy+x);
        }
        return sell0;
    }

    int maxProfitK(int K, const vector<int>& prices) {
        // O(KN), 买至多K次
        vector<int> buy(K+1), sell(K+1);
        for (const auto& x: prices) {
            for (size_t k = 1; k <= K; k++)
            {
                buy[k] = max(buy[k], sell[k-1]-x);
                sell[k] = max(sell[k], buy[k]+x);
            }
            
        }
        return sell[K];
    }

    int maxProfit2(const vector<int>& prices) {
        // O(N), 买至多2次
        int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        for (const auto& x: prices) {
            buy1 = max(buy1, -x);
            sell1 = max(sell1, buy1+x);
            buy2 = max(buy2, sell1-x);
            sell2 = max(sell2, buy2+x);
        }
        return sell2;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.maxProfit({7,1,5,3,6,4}) << endl;
    // cout << sol.maxProfit({7,6,4,3,1}) << endl;
    return 0;
}
