/*
leet301


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
    vector<string> removeInvalidParentheses(string s) {
        // 剪枝 + 回溯 28ms
        vector<string> ans;
        string path; int lft = 0, rht = 0, n = s.size();
        stack<char> S;
        for (auto &&ch : s)
        {
            if (ch == '(') lft++, S.push('(');
            if (ch == ')') {
                if (S.size() and S.top() == '(') S.pop();
                else S.push(')');
                rht++;
            }
        }

        const auto maxCnt = min(lft, rht);

        unordered_set<string> M;

        function<void(int, int, int, string)> f = [&] (int i, int lftCnt, int rhtCnt, string path) {
            if ( i - path.size() > S.size() ) return;
            if (i == n) {
                if (lftCnt == rhtCnt) M.insert(path);
                return;
            }
            
            switch (s[i])
            {
            case '(':
                if (lftCnt < maxCnt) f(i+1, lftCnt+1, rhtCnt, path + '(');
                f(i+1, lftCnt, rhtCnt, path);
                break;
            case ')':
                if (lftCnt > rhtCnt) f(i+1, lftCnt, rhtCnt+1, path + ')');
                f(i+1, lftCnt, rhtCnt, path);
                break;
            
            default:
                f(i+1, lftCnt, rhtCnt, path + s[i]);
            }

        };

        f(0, 0, 0, "");

        for (auto&& s: M) ans.push_back(s);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeInvalidParentheses("()())()") << endl;
    cout << sol.removeInvalidParentheses("(a)())()") << endl;
    cout << sol.removeInvalidParentheses(")(") << endl;
    return 0;
}
