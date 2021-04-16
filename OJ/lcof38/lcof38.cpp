/*
lcof38


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
    vector<string> permutation(string s) {
        auto n = s.size();
        vector<string> ans;
        vector<bool> used(n);
        string path;

        sort(s.begin(), s.end());

        function<void()> dfs = [&]() {
            if (n == path.size()) {
                ans.push_back(path); return;
            }

            for (size_t i = 0; i < n; i++)
            {
                if (used[i]) continue;
                 // only visit the first repeated nodes
                if (i > 0 and s[i] == s[i-1] and not used[i-1]) continue;

                used[i] = true;
                path.push_back(s[i]);
                dfs();
                path.pop_back();
                used[i] = false;
            }
        };

        dfs();
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("abbcc") << endl;
    return 0;
}
