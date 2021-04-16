/*
leet438


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
    vector<int> findAnagrams(string s, string p) {
        int Counter[26]{}, key = 0, m = p.size(), n = s.size();
        for (auto&& pi: p) Counter[pi-'a']++;
        for (int i = 0; i < 26; ++i) if (Counter[i]) key |= (1 << i);

        auto mask = key;
        for (int i = 0; i < m; ++i) {
            auto x = s[i] - 'a';
            Counter[x]--;
            if (Counter[x] == 0) key &= ~(1 << x);
        }
        vector<int> ans; 
        
        if (key == 0) ans.push_back(0);
        for (int i = 0; i < n - m; ++i) {
            auto x = s[i] - 'a', y = s[i+m] - 'a';
            Counter[x]++; if (Counter[x] == 0) key &= ~(1 << x); else key |= 1 << x;
            Counter[y]--; if (Counter[y] == 0) key &= ~(1 << y); else key |= 1 << y;
            if (key == 0) ans.push_back(i+1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findAnagrams("cbaebabacd" , "abc") << endl;
    cout << sol.findAnagrams("abab" , "ab") << endl;
    return 0;
}
