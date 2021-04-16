/*
leet130


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;


template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}


class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'H';
        if (i > 1) dfs(board, i-1, j);
        if (j > 1) dfs(board, i, j-1);
        if (i < n-1) dfs(board, i+1, j);
        if (j < m-1) dfs(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        n = board.size(), m = board[0].size();
        for (int i: {0, n-1}) 
            for (int j = 0; j < m; ++j) 
                dfs(board, i, j);
         
        for (int j: {0, m-1}) 
            for (int i = 0; i < n; ++i) 
                dfs(board, i, j);
        
        for (auto& row: board) {
            for (auto& ri: row) {
                if (ri == 'H') ri = 'O';
                else if (ri == 'O') ri = 'X';
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> B = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    Solution sol;   
    sol.solve(B);
    cout << B;
    return 0;
}
