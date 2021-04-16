/*
leet547


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


// dfs
class Solution {
public:
    int cnt;
    int n;
    vector<vector<int>> A;
    vector<bool> visited;
    void dfs(int i) {
        visited[i] = true;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] and !visited[j]) dfs(j);
        }
        
    }
    int findCircleNum(const vector<vector<int>>& isConnected) {
        n = isConnected.size();
        cnt = 0;
        A = isConnected;
        visited = vector<bool>(n);
        for (int i = 0; i < n; ++i) { 
            if (!visited[i]) { dfs(i), cnt++; }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findCircleNum({{1,1,0},{1,1,0},{0,0,1}}) << endl;
    cout << sol.findCircleNum({{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}}) << endl;
    cout << sol.findCircleNum({{1,1,1},{1,1,1,},{1,1,1},}) << endl;
    return 0;
}
