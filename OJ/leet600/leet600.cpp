/*
leet600


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
#include <bitset>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        // 0ms, 动态规划， O(32)
        // g[i] 表示 i 位数的数字中不含连续 1 的数字的个数
        // 0... g[i-1] , 10... g[i-2] => g[i] = g[i-1] + g[i-2]
        // 用 f[i] 表示 i 位数的数字中小于 num 且不含连续 1 的数字的个数
        // 0  -> f[i] = f[i-1]
        // 11 -> f[i] = g[i]
        // 10 -> f[i] = f[i-1] + g[i-1]
        const int N = 32;
        int g[N] = {2, 3};
        for (int i = 2; i < N; ++i) g[i] = g[i-1] + g[i-2];
        
        int x = 1, ans = (num & 1) + 1;
        for (int i = 1; i < N; ++i) {
            x <<= 1;
            if (x > num) break;
            if (x & num) {
                if ( (x >> 1) & num ) ans = g[i];
                else ans += g[i-1];
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;   
    
    cout << sol.findIntegers(0) << endl;
    cout << sol.findIntegers(1) << endl;
    cout << sol.findIntegers(2) << endl;
    cout << sol.findIntegers(3) << endl;
    cout << sol.findIntegers(4) << endl;
    cout << sol.findIntegers(5) << endl;
    cout << sol.findIntegers(0b1111) << endl;
    cout << sol.findIntegers(0b1011) << endl;
    cout << sol.findIntegers(0b1000) << endl;
    cout << sol.findIntegers(0b111100100) << endl;
    return 0;
}
