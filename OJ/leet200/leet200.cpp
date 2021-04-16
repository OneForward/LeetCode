/*
leet200


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int n, m, cnt;
    void dfs(vector<vector<char>>& M, int i, int j) {
        if (M[i][j] == '0') return;
        M[i][j] = '0';
        if (i > 0) dfs(M, i-1, j);
        if (i < n-1) dfs(M, i+1, j);
        if (j > 0) dfs(M, i, j-1);
        if (j < m-1) dfs(M, i, j+1);
    }
    int numIslands(vector<vector<char>>& M) {
        if (M.empty()) return 0;
        
        cnt = 0, n = M.size(), m = M[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == '1')dfs(M, i, j), cnt++;
            }
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> M = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    // vector<vector<char>> M = {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'},
    // };
    Solution sol;   
    cout << sol.numIslands(M) << endl;
    return 0;
}
