/*
leet032


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        int* f = new int[n]{};
        for (int i = 1; i < n; ++i) {
            auto j = i - 1 - f[i-1];
            if (j < 0) continue;
            if (s[j] == '(' and s[i] == ')' ) {
                if (j == 0) f[i] = f[i-1] + f[j] + 2;
                else f[i] = f[i-1] + f[j] + f[j-1] + 2;
                ans = max(ans, f[i]);
            }
        }

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestValidParentheses("()(())") << endl;
    // cout << sol.longestValidParentheses("(()") << endl;
    // cout << sol.longestValidParentheses(")()())") << endl;
    // cout << sol.longestValidParentheses("") << endl;
    // cout << sol.longestValidParentheses(")()(()()))()(()())())))") << endl;
    // cout << sol.longestValidParentheses("())") << endl;
    return 0;
}
