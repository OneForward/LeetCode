/*
leet866


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
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
    
    int primePalindrome(int N) {
        // 偶数回文串只有 11 是素数

        const int M = 10005;
        
        bool P[M]{true, true};
        vector<int> prime;
        for (int x = 2; x < M; ++x) {
            if (not P[x]) {
                prime.push_back(x);
                for (auto y = 2 * x; y < M; y += x) {
                    P[y] = true;
                }
            }
        }

        auto isPrime = [&] (int x) {
            if (x < M) return not P[x];
            for (auto&& p: prime) if (x % p == 0) return false;
            return true;
        };

        auto reverse = [](int x) {
            auto y = 0;
            while (x) {
                y = y * 10 + x % 10; x /= 10;
            }
            return y;
        };

        auto Reverse = [&](int x, int ten) {
            auto rev = reverse(x);
            return rev < ten ?  x * ten + rev : (x - x % 10) * ten + rev;
        };

        for (int x = N; x <= 11; x++) {
            if (isPrime(x)) return x;
        }

        int ten = 1;

        while (true) {
            
            for (int x = ten; x < 10 * ten; x++) {
                auto x0 = Reverse(x, ten);
                if (x0 >= N and isPrime(x0)) return x0;
            }

            ten *= 10;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.primePalindrome(6) << endl;
    cout << sol.primePalindrome(13) << endl;
    cout << sol.primePalindrome(101) << endl;
    cout << sol.primePalindrome(8) << endl;
    cout << sol.primePalindrome(61023998) << endl;
    return 0;
}
