/*
leet1044


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

const long long MOD = 1e9+7;
class Solution {
public:
    pair<long long, long long> stringHash(const string_view& s) {
        long long ans = 0, P = 1;
        for (const auto& si: s) {
            ans = ans * 26 + si - 'a';  ans %= MOD;
        }
        for (size_t i = 1; i < s.size(); i++) {
            P = P * 26 % MOD;
        }
        
        return {ans, P};
    }
    pair<bool, int> check(const string_view& s, const int K) {
        auto [key, P] = stringHash(s.substr(0, K));
        unordered_map<long long, int> S; S[key] = 0;
        // cout << key << endl;
        for (size_t i = 0; i < s.size()-K; i++)
        {
            key = (key - (s[i]-'a') * P % MOD) * 26 + s[i+K] - 'a'; key %= MOD;
            if (key < 0) key += MOD;
            auto pos = S.find(key);
            if (pos != S.end()) {
                if (s.substr(S[key], K) == s.substr(i+1, K)) return {true, i+1};
            }
                
            S[key] = i + 1;
            // cout << key << endl;
        }
        return {false, 0};
    }
    string longestDupSubstring(string s) {
        // Rabin-Karp 字符串哈希 + 二分法 O(N log N)
        int lft = 1, rht = s.size(), i = 0, K = 0;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            auto [isok, pos] = check(s, mid);
            if (isok) lft = mid + 1, i = pos, K = mid;
            else rht = mid;
        }
        return s.substr(i, K);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // sol.check("bacaca", 3);
    cout << sol.longestDupSubstring("banana") << endl;
    cout << sol.longestDupSubstring("abcd") << endl;
    return 0;
}
