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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // O(N), 动态规划, 0ms
        // f[i]: 记录以 s[i] 为终点的最长括号的长度
        // 注意：实际实现中偏移2个单位，即用 f[i+2] 代表
        int n = s.size();
        if (n <= 1) return 0;

        vector<int> f(n+2); auto ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '(') continue;
            if (s[i-1] == '(') f[i+2] = f[i] + 2;
            else {
                auto prev = i - 1 - f[i+1];
                if (prev >= 0 and s[prev] == '(') f[i+2] = f[prev+1] + f[i+1] + 2;
            }
            ans = max(ans, f[i+2]);
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestValidParentheses("(()") << endl;
    cout << sol.longestValidParentheses(")()())") << endl;
    cout << sol.longestValidParentheses("") << endl;
    cout << sol.longestValidParentheses(")()(()()))()(()())())))") << endl;
    cout << sol.longestValidParentheses("())") << endl;
    return 0;
}
