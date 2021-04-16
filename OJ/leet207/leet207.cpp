/*
leet207


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
using namespace std;

class Solution {
public:
    bool canFinish1(int n, const vector<vector<int>>& prerequisites) {
        // 基于bfs, 44ms
        vector<vector<int>> edges(n); vector<int> indegree(n);
        for (const auto& pi: prerequisites) {
            edges[pi[1]].push_back(pi[0]);
            indegree[pi[0]]++;
        }
        queue<int> Q;
        for (int i = 0; i < n; ++i) { 
            if (indegree[i] == 0) Q.push(i);
        }
        int cnt = 0;
        while (!Q.empty()) {
            auto p = Q.front(); Q.pop(); cnt++;
            for (auto neighbor: edges[p]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) Q.push(neighbor);
            }
        }
        // return all_of(indegree.begin(), indegree.end(), [](int d) { return d == 0; });
        return cnt == n;
    }

    enum Color { WHITE, GRAY, BLACK };
    vector<vector<int>> edges; 
    vector<Color> visited;

    
    bool dfs(int root) {
        if (visited[root] == GRAY) return false;
        visited[root] = GRAY;
        for (auto neighbor: edges[root]) {
            if (dfs(neighbor) == false) return false;
        }
        visited[root] = BLACK;
        return true;
    }
    bool canFinish(int n, const vector<vector<int>>& prerequisites) {
        // 基于 dfs, 28ms
        edges.resize(n);
        visited.resize(n, WHITE);
        for (const auto& pi: prerequisites) {
            edges[pi[1]].push_back(pi[0]);
        }
        
        for (int i = 0; i < n; ++i) { 
            if ( visited[i] == WHITE && dfs(i) == false)  return false;
        }        
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << boolalpha << sol.canFinish(2, {{1,0}, {0,1}}) << endl;
    // cout << boolalpha << sol.canFinish(2, {{1,0},}) << endl;
    cout << boolalpha << sol.canFinish(2, {{0,1},}) << endl;
    return 0;
}
