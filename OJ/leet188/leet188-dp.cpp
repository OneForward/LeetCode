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

    int maxProfit(int K, const vector<int>& A) {
        // O(NK)
        int n = A.size(), ans = 0;
        vector<int> buy(K+1, INT_MIN), sell(K+1);
        for (const auto& x: A)
        {
            for (size_t k = 1; k <= K; ++k) { 
                buy[k] = max(buy[k], sell[k-1]-x);
                sell[k] = max(sell[k], buy[k]+x);
            }
        }
        return sell[K];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit(2, {2, 4, 1}) << endl;
    cout << sol.maxProfit(2, {3,2,6,5,0,3}) << endl;
    return 0;
}
