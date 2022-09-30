/*
lcci01.08


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool bad_first_row{}, bad_first_col{};
        int R = matrix.size(), C = matrix[0].size();

        for (int c = 0; c < C; c++)
        {
            if (matrix[0][c] == 0) { bad_first_row = true; break; }
        }
        
        for (int r = 0; r < R; r++)
        {
            if (matrix[r][0] == 0) { bad_first_col = true; break; }
        }
        
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        
        for (int r = 1; r < R; r++)
        {
            for (int c = 1; c < C; c++)
            {
                if (matrix[r][0] == 0 or matrix[0][c] == 0) {
                    matrix[r][c] = 0; 
                }
            }
        }

        if (bad_first_row) {
            for (int c = 0; c < C; c++)
            {
                matrix[0][c] = 0;
            }
        }
        if (bad_first_col) {
            for (int r = 0; r < R; r++)
            {
                matrix[r][0] = 0;
            }
        }
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    {
        auto M = VVI
{
    {1,1,1},
    {1,0,1},
    {1,1,1},
    {1,1,1},
    {0,1,1},
    {1,1,1},
    {1,1,1},
};
        sol.setZeroes(  M );
        cout << M << endl;
    }
    return 0;
}
