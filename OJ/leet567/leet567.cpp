/*
leet567


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

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int M[26]{}, n1(s1.size()), n2(s2.size());
        if (n1 > n2) return false;

        for (const auto& ch: s1) M[ch-'a']++;
        for (int i=0; i<n1; ++i) M[s2[i]-'a']--;
        auto isok = [&] {
            for (const auto& Mi: M) if (Mi) return false;
            return true;
        };

        if (isok()) return true;
        for (int i=n1; i<n2; ++i) {
            M[s2[i]-'a']--;
            M[s2[i-n1]-'a']++;
            if (isok()) return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    cout << boolalpha;
    cout << sol.checkInclusion("ab", "eidbaooo") << endl;
    cout << sol.checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}
