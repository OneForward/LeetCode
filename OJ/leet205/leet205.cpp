/*
leet205


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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> Ms2t;
        unordered_map<char, char> Mt2s;
        for (int i = 0; i < s.size(); ++i) {
            auto si = s[i], ti = t[i];
            if (Mt2s.find(ti) == Mt2s.end()) Mt2s[ti] = si;
            else if (Mt2s[ti] != si) return false;
            if (Ms2t.find(si) == Ms2t.end()) Ms2t[si] = ti;
            else if (Ms2t[si] != ti) return false;
        }
        return true;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.isIsomorphic("aba", "baa") << endl;
    cout << boolalpha << sol.isIsomorphic("egg", "add") << endl;
    cout << boolalpha << sol.isIsomorphic("foo", "bar") << endl;
    cout << boolalpha << sol.isIsomorphic("paper", "title") << endl;
    return 0;
}
