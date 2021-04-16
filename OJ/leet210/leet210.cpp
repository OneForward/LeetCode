/*
leet210


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
    enum Color { WHITE, GRAY, BLACK };
    vector<vector<int>> edges; 
    vector<Color> visited;
    vector<int> ans;
    
    bool dfs(int root) {
        if (visited[root] == GRAY) return false;
        if (visited[root] == BLACK) return true;
        visited[root] = GRAY;
        for (auto neighbor: edges[root]) {
            if (dfs(neighbor) == false) return false;
        }
        visited[root] = BLACK; ans.push_back(root);
        return true;
    }

    vector<int> findOrder(int n, const vector<vector<int>>& prerequisites) {
        // 基于 dfs, 44ms
        edges.resize(n);
        visited.resize(n, WHITE);
        for (const auto& pi: prerequisites) {
            edges[pi[1]].push_back(pi[0]);
        }
        
        for (int u = 0; u < n; ++u) { 
            if ( visited[u] == WHITE && dfs(u) == false )  return {};
        }        
        return vector<int>(ans.rbegin(), ans.rend());
    }
};

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.findOrder(2, {{1,0}});
    cout << sol.findOrder(4, {{1,0}, {2,0}, {3,1}, {3,2}});
    return 0;
}
