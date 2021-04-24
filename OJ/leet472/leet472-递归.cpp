/*
leet472


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(const vector<string>& _words) {
        // 412ms, 78.57% Time
        unordered_set<string_view> words(_words.begin(), _words.end());
        unordered_set<string_view> visited;

        function<bool(const string_view&, bool)> dfs = [&](const string_view& word, bool first_search)->bool {
            if (words.find(word) != words.end() and not first_search) return true;
            
            for (int i=1; i < word.size(); ++i) {
                if (words.find(word.substr(0, i)) != words.end()) {
                    auto rht = word.substr(i, string_view::npos);
                    if (visited.find(rht) != visited.end()) continue;
                    if (dfs(rht, false)) return true;
                    visited.insert(rht);
                }
            }
            return false;
        };

        vector<string> ans;
        for (auto&& word: words) {
            if (dfs(word, true)) ans.push_back(string(word));
        }   
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findAllConcatenatedWordsInADict({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" }) << endl;
    cout << sol.findAllConcatenatedWordsInADict({"cat","dog","catdog"}) << endl;
    cout << sol.findAllConcatenatedWordsInADict({"a","aa","aaa"}) << endl;
    return 0;
}
