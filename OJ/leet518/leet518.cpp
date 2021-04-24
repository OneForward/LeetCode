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
        // 4ms, 完全背包, 无序
        int f[5005]{1};
        for (auto&& x:coins) {
            for (int v = x; v <= amount; ++v) {
                f[v] += f[v - x];
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
