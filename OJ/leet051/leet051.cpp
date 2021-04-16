/*
leet051


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<int> A; 
    int N; 

    void dfs(int row) {
        if (row == N) {
            // cout << A;
            vector<string> vs;
            for (auto x: A) {
                auto vc = vector<char>(N, '.');
                vc[x] = 'Q';
                vs.push_back(string(vc.begin(), vc.end()));
            }
            ans.push_back(vs);
            return;
        }

        for (int node=0; node<N; ++node) {
            if (isValid(row, node)) A[row] = node,  dfs(row+1);
        }
    }

    bool isValid(int row, int node) {
        for (int i = 0; i < row; ++i) { 
            if (node == A[i] || node+row == A[i]+i || node-row == A[i]-i) return false;
        }
        return true; 
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear(); A.resize(n); N = n;

        dfs(0);

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.solveNQueens(4) ;
    return 0;
}
