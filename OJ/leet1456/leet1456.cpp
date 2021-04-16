/*
leet1456


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
    int maxVowels(string s, int k) {
        auto isVowel = [&](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u';
        };

        int cnt = 0, ans = 0;
        for (int i = 0; i < k; ++i) { 
            if (isVowel(s[i])) cnt++;
        }
        ans = cnt;
        for (int i = k; i < s.size(); ++i) { 
            if (isVowel(s[i]) && !isVowel(s[i-k]) ) cnt++, ans = max(cnt, ans);
            if (!isVowel(s[i]) && isVowel(s[i-k]) ) cnt--;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxVowels("abciiidef", 3) << endl;
    cout << sol.maxVowels("aeiou", 2) << endl;
    cout << sol.maxVowels("leetcode", 3) << endl;
    cout << sol.maxVowels("rhythms", 3) << endl;
    return 0;
}
