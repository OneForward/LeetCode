/*
leet784


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
    vector<string> letterCasePermutation(const string& s, int start = 0) {
        if (start == s.size()) return {{s}};
        auto ans = letterCasePermutation(s, start+1);
        if (not isalpha(s[start])) return ans;
        auto si = s[start];
        auto newsi = islower(si) ? toupper(si) : tolower(si);
        auto len = ans.size();
        while (len--) {
            auto s = ans[len]; s[start] = newsi;
            ans.push_back(s);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.letterCasePermutation("a1b2") << endl;
    cout << sol.letterCasePermutation("3z4") << endl;
    cout << sol.letterCasePermutation("12345") << endl;
    return 0;
}
