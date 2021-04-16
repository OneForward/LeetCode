/*
leet087


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
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
    bool isScramble(string s1, string s2) {
        int M[30][30][31]{};
        int freq[26]{};
        auto notOk = [&](int i1, int i2, int len) {
            memset(freq, 0, sizeof freq);
            for (int k = 0; k < len; k++)
            {
                freq[s1[i1+k] - 'a']++;
                freq[s2[i2+k] - 'a']--;
            }
            return any_of(freq, freq+26, [&](int x) { return x != 0; } );
        };

        function<bool(int, int, int)> f = [&](int i1, int i2, int len) {
            if (M[i1][i2][len]) return M[i1][i2][len] == 1;
            if (notOk(i1, i2, len)) {
                M[i1][i2][len] = -1;
                return false;
            }
            if (s1.substr(i1, len) == s2.substr(i2, len)) {
                M[i1][i2][len] = 1;
                return true;
            }

            for (int k = 1; k < len; k++)
            {
                // 不交换的情况
                if (f(i1, i2, k) && f(i1 + k, i2 + k, len - k)) {
                    M[i1][i2][len] = 1;
                    return true;
                }
                // 交换的情况
                if (f(i1, i2 + len - k, k) && f(i1 + k, i2, len - k)) {
                    M[i1][i2][len] = 1;
                    return true;
                }
            }
            M[i1][i2][len] = -1;
            return false;
        };

        return f(0, 0, s1.size());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.isScramble("eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd") << endl;
    return 0;
}
