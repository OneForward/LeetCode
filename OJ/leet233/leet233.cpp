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


class Solution {
public:

    int countDigitOne(int n) {
        int x = n + 1;
        
        int ans = 0;
        for (auto ten = 1LL; ten <= x; ten *= 10) {
            auto div = ten * 10;
            ans += x / div * ten + max(min(ten, x % div - ten), 0LL);
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;   
    cout << sol.countDigitOne(1410065408) << endl;
    cout << sol.countDigitOne(10) << endl;
    cout << sol.countDigitOne(100) << endl;
    cout << sol.countDigitOne(1000) << endl;
    cout << sol.countDigitOne(99) << endl;
    cout << sol.countDigitOne(0) << endl;
    cout << sol.countDigitOne(13) << endl;
    return 0;
}
