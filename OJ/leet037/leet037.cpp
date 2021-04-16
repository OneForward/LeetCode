/*
leet037


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 9 + v.second;
    }
};

}

int cnt = 0;
class Solution {
public:
    bool isok(vector<vector<char>>& M, int i, int j) {
        
        int K = 0, row, col, square, pos, ki = i / 3 * 3, kj = j / 3 * 3;

        for (int h = 0; h < 9; ++h) {
            // cnt += 1;
            if (M[i][h] != '.') {
                pos = M[i][h] - '1'; row = 1 << pos;
                if (K & row) return false; K |= row;
            }
            if (M[h][j] != '.') {
                pos = M[h][j] - '1'; col = 1 << 9 << pos;
                if (K & col) return false; K |= col;
            }
            if (M[ki+h/3][kj+h%3] != '.') {
                pos = M[ki+h/3][kj+h%3] - '1'; square = 1 << 18 << pos;
                if (K & square) return false; K |= square;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& M) {
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (M[i][j] != '.') continue;
                for (char x = '1'; x <= '9'; ++x)  {
                    M[i][j] = x;
                    if ( isok(M, i, j) && solveSudoku(M) ) return true; 
                }
                M[i][j] = '.'; return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> M = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    // vector<vector<char>> M = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}, 
    // };

    for (auto row: M) {
        for (auto ri: row) cout << ri << " "; cout << endl;
    }

    Solution sol;
    cout << boolalpha << sol.solveSudoku(M) << endl;
    
    for (auto row: M) {
        for (auto ri: row) cout << ri << " "; cout << endl;
    }

    cout << "cnt = " << cnt << endl;


    return 0;
}
