#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int min(int a, int b, int c) {
    int ans = a;
    if (ans > b) ans = b;
    if (ans > c) ans = c;
    return ans;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int** A; 
        int length = matrix.size() + 1, width = matrix[0].size() + 1;
        A = new int*[length];
        for (int i=0; i<length; ++i) A[i] = new int[width]();
        
        for (int i=1; i<length; ++i) {
            for (int j=1; j<width; ++j) 
                if (matrix[i-1][j-1] == '1')
                    A[i][j] = min(A[i-1][j], A[i][j-1], A[i-1][j-1]) + 1;
        }

        int ans = 0;

        for (int i=1; i<length; ++i) 
            for (int j=1; j<width; ++j) 
                if (ans < A[i][j]) ans = A[i][j];

        return ans * ans;
    }
};

int main(int argc, char const *argv[])
{

    int length = 4, width = 5;
    
    vector<vector<char>> M{ {'1','0','1','0','0'},
                            {'1','0','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','0','0','1','0'}};
    
        
   Solution solution;
   int ans = solution.maximalSquare(M);

    printf("ans = %d\n", ans);

    return 0;
        
}
