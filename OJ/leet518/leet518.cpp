/*
leet518


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
    int change(int amount, const vector<int>& coins) {
        // 4ms, 完全背包
        vector<int> f(amount+1);
        f[0] = 1;
        for (auto coin: coins) {
            for (auto v = coin; v <= amount; ++v) {
                f[v] += f[v-coin]; v++;
            }
        }
        return f[amount];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.change(5, {1,2,5}) << endl;
    cout << sol.change(3, {2}) << endl;
    cout << sol.change(10, {10 }) << endl;
    return 0;
}
