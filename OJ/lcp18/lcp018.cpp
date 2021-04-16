/*
lcp018


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
    int breakfastNumber(vector<int> staple, vector<int> drinks, int t) {
        // O(N log N)
        const int MOD = 1e9 + 7;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int ans = 0, rht = drinks.size() - 1;
        for (const auto& x: staple) {
            while (rht >= 0 and  drinks[rht] + x > t) rht--;
            if (rht == -1) break;
            ans += rht + 1; ans %= MOD;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.breakfastNumber({10,20,5}, {5,5,2}, 15) << endl;
    return 0;
}
