/*
leet5725


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(const vector<int>& A) {
        bool f[20005]{};
        for (auto&& x: A) f[x] = true;
        int cnt = 0;
        auto gcd = [](int x, int y) {
            if (y) while ( (x %= y) and (y %= x));
            return x + y;
        };
        auto check = [&] (int x) -> bool {
            auto start = 0;
            for (int y = x; y <= 10000; y += x) {
                if (f[y]) { start = y; break; }
            }
            for (int y = start; y <= 10000; y += x) {
                if (start < x) return false;
                if (f[y]) { 
                    start = gcd(start, y);  
                    if (start == x) return true;
                }
            }
            return false;
        };
        for (int x = 1; x <= 10000; ++x) {
            if (check(x)) cnt++;
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countDifferentSubsequenceGCDs({6,10,3}) << endl;
    cout << sol.countDifferentSubsequenceGCDs({5,15,40,5,6}) << endl;
    return 0;
}
