/*
leet048


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
    void rotate(vector<vector<int>>& matrix) {
        // 4ms
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) 
            for (size_t j = i+1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        for (size_t i = 0; i < n; ++i) 
            for (size_t j = 0; j < n/2; ++j)
                swap(matrix[i][j], matrix[i][n-1-j]);
        
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> M = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    sol.rotate(M);
    for (auto row: M) {
        for (auto ri: row) {
            cout << ri << ", ";
        }
        cout << endl;
    }

    return 0;
}
