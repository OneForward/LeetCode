/*
leet212


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
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

struct Trie
{
    Trie* next[27]{};
    string isleaf = "";
    int len = 0;
    
    Trie() {}
    void addword(const string& word) {
        auto p = this;
        for (const auto& ch:word) {
            if (p->next[ch-'a'] == nullptr) p->next[ch-'a'] = new Trie(), p->len++;
            p = p->next[ch-'a'];
        }
        p->isleaf = word;
    }
};

const int Neighbors[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void find(vector<string>& ans, int x, int y, vector<vector<char>>& board, Trie* p) {
    int n = board.size(), m = board[0].size();
    if (x < 0 or y < 0 or x >= n or y >= m ) return;
    auto ch = board[x][y];
    if (not p->next[ch-'a']) return;

    auto curNode = p->next[ch-'a'];
    if (curNode->isleaf.size()) ans.push_back(curNode->isleaf), curNode->isleaf = "";

    board[x][y] = '{'; // 灵魂步骤：设置已访问
    for (const auto [dx, dy]: Neighbors) {
        auto nx = x + dx, ny = y + dy;
        find(ans, nx, ny, board, curNode);
    }
    board[x][y] = ch;

    // 灵魂步骤：裁剪 Trie
    if (curNode->len == 0) p->next[ch-'a'] = nullptr, p->len--;
}

class Solution {
public:

    vector<string> findWords(vector<vector<char>> board, const vector<string>& words) {
        // 0ms, Trie
        Trie trie; 
        for (const auto& word: words) trie.addword(word);

        int n = board.size(), m = board[0].size();
        vector<string> ans;
        for (int x = 0; x < n; ++x) { 
            for (int y = 0; y < m; ++y) { 
                find(ans, x, y, board, &trie);
            }
        }
        return ans;
    }

};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findWords({{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}, {"oath","pea","eat","rain"}) << endl;
    cout << sol.findWords({{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}
}, {"oa","oaa",}) << endl;
    return 0;
}
