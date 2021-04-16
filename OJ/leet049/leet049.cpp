/*
leet049


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 80ms
        unordered_map<string, vector<string>> dict;
        for (const auto& si: strs) {
            string s = si;
            sort(s.begin(), s.end());
            auto [ptr, ok] = dict.insert({s, {si}});
            if (!ok) ptr->second.push_back(si);
        }
        vector<vector<string>> ans;
        for (const auto& item: dict) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution sol;   
    auto ans = sol.groupAnagrams(strs);

    for (auto row: ans) {
        for (auto ri: row) cout << ri << ", ";
        cout << endl;
    }
    return 0;
}
