/*
leet140


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

string joinString(const vector<string>& vs, string delim=" ") {
    if (vs.empty()) return {};
    string s = vs[0];
    for (size_t i = 1; i < vs.size(); i++)
    {
        s += delim + vs[i];
    }
    return s;
}

class Solution {
public:
    vector<string> wordBreak(string s, const vector<string>& wordDict) {
        unordered_set<string> M(wordDict.begin(), wordDict.end());
        
        int n =  s.size(); vector<string> path, ans;
        function<void(size_t)> f = [&](size_t lft) {
            if (lft == n) {
                ans.push_back(joinString(path));
                return;
            }

            for (size_t rht = lft; rht < n; rht++)
            {
                auto sub = s.substr(lft, rht-lft+1);
                if (M.find(sub) != M.end()) {
                    path.push_back(sub);
                    f(rht+1);
                    path.pop_back();
                }
            }
            
        };

        f(0);
        return ans;

    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"}) << endl;
    return 0;
}
