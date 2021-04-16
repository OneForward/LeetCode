/*
leet479


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

class Solution {
public:


    int largestPalindrome2(int n) {
        // TLE
        if (n == 1) return 9;
        
        auto isPalindrome = [](long long x) {
            long long ans = 0, x0 = x;
            while (x) {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
            return ans == x0;
        };

        const auto base = pow(10ll, n-1);
        long long xy = 0;
        for (long long i = base * 10; i > base * 9; --i)
        {
            if (i * i < xy) break;
            for (long long j = i; j > base * 9; --j){
                const auto ij = i * j;
                if (ij < xy) break;
                if (isPalindrome(ij)) {
                    xy = ij;
                    break;
                }
            }
        }
        return xy % 1337;
    }

    int largestPalindrome3(int n) {
        // 56ms
        // 1. 偶数长度的回文数一定被 11 整除
        // 2. 对回文数自顶向下遍历即可
        using ll = long long;
        auto toPalindrome = [](ll x) {
            ll ans = x;
            while (x) {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
            return ans;
        };

        const ll hi = pow(10, n) - 1;
        const ll lo = pow(10, n-1);
        for (ll half = hi; half >= lo; --half) {
            const auto xy = toPalindrome(half);
            for (ll x = hi - hi % 11; x > xy / hi; x -= 11) {
                if (xy % x == 0) return xy % 1337;
            }
        }
        return 9;
    }
    int largestPalindrome(int n) {
        // 0ms
        // (10^n - x) (10^n - y) = (10^n - x - y) 10^n + xy 是回文
        //  需要 b = xy = reverse(10^n - a) , a = x + y
        // 此时需要判别式 a^2 - 4 b 为完全平方数
        auto reverse = [](int x) {
            int ans = 0;
            while (x) {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
            return ans;
        };

        auto isSquare = [](int x) {
            if (x < 0) return false;
            int y = sqrt(x);
            return y * y == x;
        };

        const int MOD = 1337;
        const int hi = pow(10, n);
        const int lo = pow(10, n-1);
        for (int a = 1; a < hi; ++a) {
            const auto b = reverse(hi - a);
            if (isSquare(a * a - 4 * b)) return (((hi - a) % MOD) * (hi % MOD) + b) % MOD;
        }
        return 9;
    }

    int largestPalindrome1(int n) {
        // 0ms
        const int f[] = { 0, 9, 987, 123, 597, 677, 1218, 877, 475 };
        return f[n];
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;
    for (size_t n = 1; n <= 8; n++)
    {
        cout << sol.largestPalindrome(n) << ", ";
    }
    

    

    return 0;
}
