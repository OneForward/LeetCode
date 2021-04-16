/*
leet1074


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget1(const vector<vector<int>>& matrix, int target) {
        // O(R^2 C^2), 1072ms
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> colAcc = matrix;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                colAcc[i][j] += colAcc[i-1][j];
            }
        }

        int ans = 0;
        for (int x1 = 0; x1 < n; ++x1) { 
            for (int x2 = x1; x2 < n; ++x2) { 
                for (int y1 = 0; y1 < m; ++y1) { 
                    const auto& row1 = colAcc[x1], &row2 = colAcc[x2], &row = matrix[x1];
                    int sum = 0;
                    for (int y2 = y1; y2 < m; ++y2) { 
                        sum += row2[y2] - row1[y2] + row[y2];
                        if (sum == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
    int numSubmatrixSumTarget(const vector<vector<int>>& matrix, int target) {
        // O(R^2 C^2), 172ms
        int n = matrix.size(), m = matrix[0].size();

        int ans = 0; int* colAcc;
        for (int x1 = 0; x1 < n; ++x1) { 
            colAcc = new int[m]{};
            for (int x2 = x1; x2 < n; ++x2) { 
                for (int y = 0; y < m; ++y) { 
                    colAcc[y] += matrix[x2][y];
                }
                for (int y1 = 0; y1 < m; ++y1) {
                    int sum = 0;   
                    for (int y2 = y1; y2 < m; ++y2) { 
                        sum += colAcc[y2];
                        if (sum == target) ans++;
                    }
                }
            }
        }
        return ans;
    }

    int numSubmatrixSumTarget2_1(const vector<vector<int>>& matrix, int target) {
        // O( R^2 C), 768ms

        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> colAcc = matrix;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                colAcc[i][j] += colAcc[i-1][j];
            }
        }

        int ans = 0;
        for (int x1 = 0; x1 < n; ++x1) { 
            for (int x2 = x1; x2 < n; ++x2) { 
                auto row = matrix[x1]; 
                for (int i = 0; i < m; ++i) row[i] += colAcc[x2][i] - colAcc[x1][i] ;
                unordered_map<int, int> M; int pre = 0; M[0] = 1;
                for (const auto& x: row) {
                    pre += x;
                    if (M.find(pre - target) != M.end()) {
                        ans += M[pre-target];
                    }
                    M[pre]++;
                }
            }
        }
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numSubmatrixSumTarget({{0,1,0},{1,1,1},{0,1,0}}, 0) << endl;
    cout << sol.numSubmatrixSumTarget({{1,-1},{-1,1}}, 0) << endl;
    return 0;
}
