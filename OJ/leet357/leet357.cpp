/*
leet357


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

class Solution1 {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        auto f20 = 0, f2 = 9, f1 = 1, ans = 10;
        for (int i = 2; i <= n; i++)
        {
            f1 = (11 - i) * (f1 + f20);
            f20 = f2; f2 *= (10 - i);
            ans += f1 + f2;
        }
        return ans;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        auto f = 0, cnt = 0, ten = 1;
        for (int i = 1; i < n; i++)
        {
            f = 10 * f + i * (9 * ten - f);
            ten *= 10; 
            cnt += f;
        }
        return 10 * ten - cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countNumbersWithUniqueDigits(1) << endl;
    cout << sol.countNumbersWithUniqueDigits(2) << endl;
    cout << sol.countNumbersWithUniqueDigits(3) << endl;
    return 0;
}
