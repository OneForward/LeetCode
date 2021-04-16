/*
leet394


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

class Solution {
public:
    string decodeString(string s) {
        vector<string> S1;
        stack<int> S2;
        
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                auto x = 0;
                while (isdigit(s[i])) {
                    x = x * 10 + s[i] - '0'; ++i;
                } 
                S2.push(x); S1.push_back("");
            }
            else if (islower(s[i])) {
                string sub;
                while (islower(s[i])) sub.push_back(s[i]), ++i; --i;
                if (S1.size() and S1.back().size()) S1.back() += sub; 
                else S1.push_back(sub);
            }
            else {// ']'
                string small;
                while ( S1.back().size() ) {
                    auto sub = S1.back(); S1.pop_back();
                    auto x = S2.top(); S2.pop();
                    while (x--) small += sub; 
                }
                S1.pop_back();

                if (S1.size() and S1.back().size()) S1.back() += small; 
                else S1.push_back(small);
            }
        }
        string ans;
        for (auto&& sub: S1) ans += sub;
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;
    cout << sol.decodeString("3[a]2[bc]") << endl;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    cout << sol.decodeString("abc3[cd]xyz") << endl;
    return 0;
}
