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
using namespace std;

class Solution {
public:
    vector<vector<bool>> searched;
    int m, n;

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int k) {
        if (board[i][j] != word[k] || searched[i][j]) return false;

        searched[i][j] = true;
        if ( k == word.size()-1 ) {
            searched[i][j] = false;
            return true;
        }
        if (i > 0 ) if (dfs(board, i-1, j, word, k+1)) return true;
        if (i < m-1 ) if (dfs(board, i+1, j, word, k+1)) return true;
        if (j > 0 ) if (dfs(board, i, j-1, word, k+1)) return true;
        if (j < n-1 ) if (dfs(board, i, j+1, word, k+1)) return true;
        searched[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // 32ms
        m = board.size(), n = board[0].size();
        searched = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'},
    };
    // vector<vector<char>> board = {
    //     {'A','B','C','E'},
    //     {'S','F','C','S'},
    //     {'A','D','E','E'}
    // };

    Solution sol;   
    cout << boolalpha << sol.exist(board, "AAB") << endl;
    // cout << boolalpha << sol.exist(board, "ABCCED") << endl;
    // cout << boolalpha << sol.exist(board, "SEE") << endl;
    // cout << boolalpha << sol.exist(board, "ABCB") << endl;
    return 0;
}
