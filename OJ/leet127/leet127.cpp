/*
leet127


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
    unordered_map<string, int> M;
    vector<vector<int>> edges;
    int N = 0;

    int addWord(string& word) {
        if (M.find(word) == M.end()) {
            M[word] = N++;  
            edges.emplace_back();
        }
        return M[word];
    }

    void addEdge(string& word) {
        auto start = addWord(word);
        for (auto& wi: word)
        {
            auto ch = wi;
            wi = '*';
            auto to = addWord(word);
            wi = ch;

            edges[start].push_back(to);
            edges[to].push_back(start);
        }
        
    }

    int ladderLength(string beginWord, string endWord, vector<string> wordList) {
        // 120ms, BFS
        addEdge(beginWord);
        for (auto& word: wordList) addEdge(word);
        if (M.count(endWord) == 0) return 0;

        vector<bool> visited(N);

        auto start = M[beginWord], end = M[endWord], ans = 0;
        queue<int> Q; Q.push(start); visited[start] = true;
        while (Q.size()) {
            auto len = Q.size();
            ans++;
            while (len--) {
                auto from = Q.front(); Q.pop();
                for (const auto& to: edges[from]) {
                    if (to == end)  return ans / 2 + 1;
                    if (not visited[to]) Q.push(to), visited[to] = true;
                }
            }
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << endl;
    cout << sol.ladderLength("hit", "cog", {"hot","dot","dog","lot","log",}) << endl;
    return 0;
}
