/*
lcci08.08


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
    vector<string> permutation(string s, int start ) {
        if (start == s.size() - 1) return {s};
        auto ans = permutation(s, start+1);
        auto len = ans.size();
        while (len--) {
            auto s = ans[len];
            for (size_t i = start + 1; i < s.size(); i++)
            {
                swap(s[start], s[i]);
                ans.push_back(s);
                swap(s[start], s[i]);
            }
        }
        return ans;
    }
    vector<string> permutation(string s ) {
        auto ans = permutation(s, 0);
        unordered_set<string> M(ans.begin(), ans.end());
        return vector<string>(M.begin(), M.end());
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("aaabb") << endl;
    cout << sol.permutation("abb") << endl;
    cout << sol.permutation("ab") << endl;
    return 0;
}
