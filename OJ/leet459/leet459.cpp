/*
leet459


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool check(string_view S, int m) {
        string_view P = S.substr(0, m);
        int start = m;
        while (start < S.size()) {
            string_view P2 = S.substr(start, m);
            if (P != P2) return false;
            start += m;
        }
        return true;
    }
    bool repeatedSubstringPattern1(string_view s) {
        // 朴素解法, 28ms, Time 62.40% Space 100%
        int n = s.size();
        for (int m = 1; m <= n/2; ++m) {
            if ( n % m == 0 && check(s, m)) return true;
        }
        return false;
    }
    bool repeatedSubstringPattern(string s) {
        // 奇妙解法, 16ms
        return (s + s).find(s, 1) != s.size();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.repeatedSubstringPattern("abab") << endl;
    cout << boolalpha << sol.repeatedSubstringPattern("aba") << endl;
    cout << boolalpha << sol.repeatedSubstringPattern("abcabcabcabc") << endl;
    return 0;
}
