/*
leet126


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

    vector<vector<string>> findLadders(string beginWord, string endWord, const vector<string>& wordList) {
        // BFS 找最短距离并记录父节点， DFS找路径
        unordered_set<string> S(wordList.begin(), wordList.end()); 
        if (S.count(endWord) == 0) return {};

        queue<string> Q; Q.push(endWord); S.insert(beginWord); S.erase(endWord);
        vector<vector<string>> ans;
        vector<string> path;
        unordered_map<string, unordered_set<string>> parent;

        function<void(const string& node, vector<string>&)> dfs = [&](const string& node, vector<string>& path) {
            path.push_back(node);
            if (node == endWord) ans.push_back(path); 
            for (const auto& pa: parent[node]) {
                dfs(pa, path);
            }
            path.pop_back();
        };
        while (Q.size()) {
            auto len = Q.size();
            auto found = false;
            unordered_set<string> next;

            while (len--) {
                auto word = Q.front(); Q.pop();
                auto oldword = word;
                for (auto& wi: word) {
                    auto old = wi;
                    for (auto ch = 'a'; ch <= 'z'; ++ch) {
                        wi = ch;
                        if (word == beginWord) found = true;
                        if (S.find(word) != S.end()) {
                            parent[word].insert(oldword);
                            next.insert(word);
                        }
                    }
                    wi = old;
                }
            }
            for (const auto& word: next) {
                Q.push(word); S.erase(word);
            }
            if (found) {
                dfs(beginWord, path);
                return ans;
            }
        }
        
        return {};

    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findLadders("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << endl;
    cout << sol.findLadders("hit", "cog", {"hot","dot","dog","lot","log",}) << endl;
    return 0;
}
