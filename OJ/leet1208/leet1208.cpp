/*
leet1208


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int equalSubstring(const string& s, string t, int maxCost) {
        int lft = 0, rht = 0, ans = 0, cost = 0;
        for (int rht = 0; rht < s.size(); ++rht) {
            cost += abs(s[rht] - t[rht]);
            while (cost > maxCost) cost -= abs(s[lft] - t[lft]), lft++;
            ans = max(ans, rht - lft + 1);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.equalSubstring("abcd", "bcdf", 3) << endl;
    cout << sol.equalSubstring("abcd", "cdef", 3) << endl;
    cout << sol.equalSubstring("abcd", "acde", 0) << endl;
    return 0;
}
