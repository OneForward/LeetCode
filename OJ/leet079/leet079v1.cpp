/*
leet079


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include <functional>
using namespace std;

class Solution {
public:
    bool exist(const vector<vector<char>>& board, string word) {
        const int DIR[][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

        const int R = board.size(), C = board[0].size(), len = word.size();
        bool visited[200][200]{};

        function<bool(int, int, int)> dfs = [&](int r, int c, int i) {
            if (board[r][c] != word[i]) return false;
            if (i == len - 1) return true;
            visited[r][c] = true;
            for (auto&& [dx, dy]: DIR) {
                auto x = r + dx, y = c + dy;
                if (x < 0 or y < 0 or x >= R or y >= C or visited[x][y]) continue;
                if (dfs(x, y, i+1)) return true;
            }
            visited[r][c] = false;
            return false;
        };

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<char>> board = {
    //     {'A','B','C','E'},
    //     {'S','F','C','S'},
    //     {'A','D','E','E'}
    // };

    Solution sol;   
    cout << boolalpha;
    cout << sol.exist({
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'},
    }, "CAB") << endl;
    // cout << sol.exist({
    //     {'A','B','C','E'},
    //     {'S','F','C','S'},
    //     {'A','D','E','E'}
    // }, "ABCCED") << endl;
    // cout << boolalpha << sol.exist(board, "ABCCED") << endl;
    // cout << boolalpha << sol.exist(board, "SEE") << endl;
    // cout << boolalpha << sol.exist(board, "ABCB") << endl;
    return 0;
}
