/*
leet1021


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string removeOuterParentheses(const string& s) {
        int f = 0;
        string ans; ans.reserve(s.size());
        for (auto&& ch: s)
        {
            if (ch == ')') f--;
            if (f) ans += ch;
            if (ch == '(') f++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeOuterParentheses("(()())(())") << endl;
    cout << sol.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << sol.removeOuterParentheses( "()()") << endl;
    return 0;
}
