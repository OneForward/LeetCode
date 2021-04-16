/*
offer048


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window 
        vector<bool> S(256);
        int lft = 0, ans = 0;
        for (int rht = 0; rht < s.size(); rht++)
        {
            while (S[s[rht]] == true) {
                S[s[lft]] = false; lft++;
            }
            S[s[rht]] = true;
            ans = max(ans, rht - lft + 1);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
