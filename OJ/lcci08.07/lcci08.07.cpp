/*
lcci08.07


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
    vector<string> permutation(string s, int start = 0) {
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
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("abc") << endl;
    cout << sol.permutation("ab") << endl;
    return 0;
}
