/*
leet1763


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

bool isok(const string& s, int lft, int rht) {
    bool M[255]{}; auto ok = true;
    for (int i = lft; i < rht; ++i) M[s[i]] = true;
    for (int i = lft; i < rht; ++i) {
        if (islower(s[i]) and M[toupper(s[i])]) continue;
        if (isupper(s[i]) and M[tolower(s[i])]) continue;
        ok = false; break;
    }
    return ok;
}

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        pair<int, int> ans{};
        for (size_t lft = 0; lft < n; lft++)
        {
            for (size_t rht = lft+1; rht <= n; rht++)
            {
                auto& [st, len] = ans;
                if (isok(s, lft, rht)) {
                    if (rht - lft > len) ans = {lft, rht - lft};
                }
            }
        }
        
        auto [st, len] = ans;
        return s.substr(st, len);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.longestNiceSubstring("YazaAay") << endl;
    cout << sol.longestNiceSubstring("Bb") << endl;
    return 0;
}
