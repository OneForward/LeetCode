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


const int Neighbors[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int n, m;

    bool find(int x, int y, vector<vector<char>>& board, const string& word, int start=0) {
        if (x < 0 or y < 0 or x >= n or y >= m ) return false;
        
        auto ch = board[x][y];
        if (word[start] != ch) return false;

        start++;
        if (start == word.size()) return true;

        board[x][y] = '{'; // 灵魂步骤：设置已访问
        for (const auto [dx, dy]: Neighbors) {
            auto nx = x + dx, ny = y + dy;
            if (find(nx, ny, board, word, start)) {
                board[x][y] = ch;
                return true;
            }
        }
        board[x][y] = ch;
        return false;
    }

    vector<string> findWords(vector<vector<char>> board, const vector<string>& words) {
        // 4ms, dfs

        n = board.size(), m = board[0].size();
        vector<string> ans;

        for (const auto& word: words) {
            for (int x = 0; x < n; ++x) { 
                for (int y = 0; y < m; ++y) { 
                    if (find(x, y, board, word)) {
                        ans.push_back(word); goto loop;
                    }
                }
            }
            loop: ;
        }

        return ans;
    }

};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findWords({{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}, {"oath","pea","eat","rain"}) << endl;
    cout << sol.findWords({{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}}, {"oa","oaa",}) << endl;
    cout << sol.findWords({{'a', 'a'}}, {"aaa",}) << endl;
    return 0;
}
