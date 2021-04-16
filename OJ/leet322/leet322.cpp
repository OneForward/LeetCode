/*
leet322


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;



class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {
        // Time O(NV), Space O(V), N 为物品类别数目, V 为背包容量
        // 完全背包的最小装件数目问题
        vector<int> f(amount+1, amount + 1);
        f[0] = 0;
        for (auto coin: coins) {
            auto v = coin;
            while (v <= amount) {
                f[v] = min(f[v], f[v-coin]+1 );
                v++;
            }
        }
        
        return f[amount] > amount ? -1 : f[amount];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.coinChange({1,2,5}, 11) << endl;
    cout << sol.coinChange({186,419,83,408}, 6249) << endl;
    cout << sol.coinChange({2}, 3) << endl;
    return 0;
}
