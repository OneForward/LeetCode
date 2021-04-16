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


// bfs
class Solution {
public:

    int findCircleNum(const vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<vector<int>> A = isConnected;
        queue<int> Q;
        vector<bool> visited(n);

        for (int i = 0; i < n; ++i) { 
            if (!visited[i]) {
                cnt++; 
                Q.push(i); visited[i] = true;

                while (!Q.empty()) {
                    int x = Q.front(); Q.pop();
                    for (int j = 0; j < n; ++j) { 
                        if (A[x][j] && !visited[j]) {
                            Q.push(j); visited[j] = true;
                        }
                    }
                }
            }
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
