/*
leet233


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

// int f [] = { 0, 1, 19, 271, 3439, 40951, 468559, 5217031, 56953279, 612579511, };
unordered_map<int, int> f = {{ 10, 1 }, { 100, 19 }, { 1000, 271 }, { 10000, 3439 }, { 100000, 
40951 }, { 1000000, 468559 }, { 10000000, 5217031 }, { 100000000, 
56953279 }, { 1000000000, 612579511 },};

class Solution {
public:
    int countDigitOne(int n, int base)  {
        if (base == 1) return 0;
        if (n < base) return countDigitOne(n, base/10);

        if (n >= 2 * base) {
            auto k = n / base - 1;
            return k * f[base] + countDigitOne(n % base) + base;
        }
        return f[base] + n - base + 1;
    }
    int countDigitOne(int n) {
        return countDigitOne(n, 1000000000);
    }
};


int main(int argc, char const *argv[])
{
    
    // map<int, int> f;
    // f[10] = 1; 
    // int x = 10;
    // while (x < INT_MAX / 10) {
    //     f[10*x] = f[x] * 9 + x;
    //     x *= 10;
    // }
    // for (const auto& fx: f) cout << fx << ", ";
    
    
    
    Solution sol;   
    cout << sol.countDigitOne(100) << endl;
    cout << sol.countDigitOne(0) << endl;
    cout << sol.countDigitOne(13) << endl;
    return 0;
}
