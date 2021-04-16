/*
leet073


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
    void setZeroes(vector<vector<int>>& matrix) {
        // 32ms, inplace, Space O(1)
        size_t m = matrix.size(), n = matrix[0].size();
        bool first_row = false, first_col = false;
        for (size_t i = 0; i < m; ++i) if (matrix[i][0] == 0) { first_col = true; break; }
        for (size_t j = 0; j < n; ++j) if (matrix[0][j] == 0) { first_row = true; break; }

        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
            }
        }
        for (size_t i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; ++j) matrix[i][j] = 0;
            }
        }
        for (size_t j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; ++i) matrix[i][j] = 0;
            }
        }

        if (first_row) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (first_col) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }

    }
    void setZeroes2(vector<vector<int>>& matrix) {
        // only ok for less than 64 rows and cols
        size_t m = matrix.size(), n = matrix[0].size();
        unsigned long long int row = 0, col = 0, one = 1;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row |= one << i; col |= one << j;
                }
            }
        }
        for (size_t i = 0; i < m; ++i) {
            if (row & (one << i)) {
                for (int j = 0; j < n; ++j) matrix[i][j] = 0;
            }
        }
        for (size_t j = 0; j < n; ++j) {
            if (col & (one << j)) {
                for (int i = 0; i < m; ++i) matrix[i][j] = 0;
            }
        }

    // }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> M = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    // vector<vector<int>> M = {
    //     {1,1,1}, {0, 1, 2}
    // };

    Solution sol;   
    sol.setZeroes(M);
    for (auto row: M) {
        for (auto ri: row) 
            cout << ri << ", "; 
        cout << endl;
    }
    return 0;
}
