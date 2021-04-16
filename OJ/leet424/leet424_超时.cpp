/*
leet424
sliding window

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
    int characterReplacement(string s, int k) {
        // O(26 n^2) 超时
        int n = s.size(), ans = 0;
        for (int len = n; len > k; --len) { 
            vector<int> Counter(26);
            auto top = [&]() {
                return *max_element(Counter.begin(), Counter.end());
            };
            for (int i = 0; i < len; ++i) {
                Counter[s[i]-'A']++;
            }
            if (top() + k >= len) return len;
            for (int i = 0; i < n-len; ++i) { 
                Counter[s[i]-'A']--;
                Counter[s[i+len]-'A']++;
                if (top() + k >= len) return len;
            }
        }
        return k;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.characterReplacement("BAAA", 0) << endl;
    // cout << sol.characterReplacement("ABAA", 0) << endl;
    // cout << sol.characterReplacement("ABAB", 2) << endl;
    // cout << sol.characterReplacement("AABABBA", 1) << endl;
    return 0;
}
