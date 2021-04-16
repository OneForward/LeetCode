/*
leet131


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
    vector<vector<string>> partition(string s) {
        int n  = s.size();
        vector<vector<int>> f(n);
        
        for (int i = 0; i < n; i++)
        {
            for (int L = 0; i-L>=0 and i+L < n; L++)
            {
                if (s[i-L] == s[i+L]) f[i-L].push_back(i+L);
                else break;
            }
            for (int L = 0; i-L>=0 and i+L+1 < n; L++)
            {
                if (s[i-L] == s[i+L+1]) f[i-L].push_back(i+L+1);
                else break;
            }
        }
        
        vector<vector<string>> ans;
        vector<string> path, rpath;
        int len = 0;
        function<void(int)> dfs = [&](int lft) {
            if (lft == n) {
                ans.emplace_back(path);
                return;
            }
            for (auto&& x: f[lft]) 
            {
                path.push_back(s.substr(lft, x - lft + 1)); len += x - lft + 1;
                dfs(x+1);
                path.pop_back(); len -= x - lft + 1;
            }
        };

        dfs(0);

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.partition("aaa") << endl;
    cout << sol.partition("aab") << endl;
    cout << sol.partition("aa") << endl;
    return 0;
}
