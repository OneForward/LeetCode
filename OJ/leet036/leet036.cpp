/*
leet036

bit运算
*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool isValidSudoku2(vector<vector<char>>& M) {
        // 28ms
        vector<vector<bool>> rows(9, vector<bool>(9));
        vector<vector<bool>> cols(9, vector<bool>(9));
        vector<vector<bool>> square(9, vector<bool>(9));

        int pos, k;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (M[i][j] == '.') continue;
                pos = M[i][j] - '1'; k = i / 3 * 3 + j / 3;
                if (rows[i][pos] || cols[pos][j] || square[k][pos]) return false;
                rows[i][pos] = true;
                cols[pos][j] = true;  
                square[k][pos] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& M) {
        // 16ms
        vector<int> K(9, 0);
        int row, col, square;

        int pos, k;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (M[i][j] == '.') continue;
                pos = M[i][j] - '1'; k = i / 3 * 3 + j / 3;
                row = 1 << pos; col = 1 << 9 << pos; square = 1 << 18 << pos;
                if ((K[i] & row) | (K[j] & col) | (K[k] & square) ) return false;
                K[i] |= row;
                K[j] |= col;
                K[k] |= square;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> M = {
        {'8','3','.','.','7','.','.','.','.'},
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

    Solution sol;
    cout << boolalpha << sol.isValidSudoku(M) << endl;
    return 0;
}
