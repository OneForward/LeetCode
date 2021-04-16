/*
leet063


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
    int uniquePathsWithObstacles3(vector<vector<int>>& obstacleGrid) {
        // 8ms, Space O(1) Time O(MN)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        obstacleGrid[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0]) { obstacleGrid[i][0] = 0;}
            else obstacleGrid[i][0] = obstacleGrid[i-1][0];
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j]) { obstacleGrid[0][j] = 0;}
            else obstacleGrid[0][j] = obstacleGrid[0][j-1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        // 8ms, Space O(NM) Time O(MN)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m+1, vector<int>(n+1));
        f[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i-1][j-1]) f[i][j] = 0;
                else f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 8ms, Space O(N) Time O(MN)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> f(n+1, 0);
        f[1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i-1][j-1]) f[j] = 0;
                else f[j] += f[j-1];
            }
        }
        return f[n];
    }
};

int main(int argc, char const *argv[])
{
//     vector<vector<int>> obstacleGrid = {
//   {0},{1},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1},{0},{0},{0},{0},{1},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1},{1},{0},{1},{0},{0},{1},{0},{0},{0},{0},{1}
//     };
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0},
    };
    Solution sol;   
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
