/*
leet310


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

class Solution1 {
public:
    int get_height(int root, const vector<vector<int>>& edges) {
        vector<bool> visited(edges.size());
        return get_height(root, edges, visited);
    }
    int get_height(int root, const vector<vector<int>>& edges, vector<bool>& visited) {
        int h = 0; visited[root] = true;
        for (auto neighbor: edges[root]) {
            if (!visited[neighbor]) h = max(h, get_height(neighbor, edges, visited));
        } 
        return h+1;
    }
    vector<int> findMinHeightTrees(int n, const vector<vector<int>>& E) {
        // TLE
        vector<vector<int>> edges(n);  
        for (const auto& e: E) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }

        vector<int> height(n); vector<int> ans;
        for (int i = 0; i < n; ++i) height[i] = get_height(i, edges);
        
        int minval = INT_MAX;
        for (auto h: height) minval = min(minval, h);
        for (int i = 0; i < n; ++i) if (minval == height[i]) ans.push_back(i);
        return ans;
    }   
};
class Solution2 {
public:

    vector<int> findMinHeightTrees(int n, const vector<vector<int>>& E) {
        // 自外向内逐步删除最外层的结点, 244ms
        vector<vector<int>> edges(n);  vector<int> indegree(n);
        for (const auto& e: E) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        unordered_set<int> S;
        for (int i = 0; i < n; ++i) S.insert(i);

        while (true) {
            vector<int> ans;
            for (int i: S) {
                if (indegree[i] == 1) {
                    indegree[i] = 0;
                    ans.push_back(i), S.erase(i);
                    for (auto neighbor: edges[i]) {
                        if (S.find(neighbor) == S.end()) continue;
                        indegree[neighbor]--;
                    }
                }
            }
            if (S.empty()) return ans;
            else if (S.size() == 1) return { *S.begin() };
        }
        
        return {};
    }   
};
class Solution {
public:

    vector<int> findMinHeightTrees(int n, const vector<vector<int>>& E) {
        // 自外向内逐步删除最外层的结点, 112ms, 97.07%
        vector<vector<int>> edges(n);  vector<int> indegree(n);
        for (const auto& e: E) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> Q; 
        for (int i = 0; i < n; ++i) if (indegree[i] <= 1) Q.push(i); 
        int cnt = Q.size();
        while (n > 2) {
            n -= cnt; 
            while (cnt--) {
                auto p = Q.front(); Q.pop();
                for (auto neighbor: edges[p]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1) Q.push(neighbor);
                }
            }
            cnt = Q.size();
        }
        
        vector<int> ans;
        while (!Q.empty()) ans.push_back(Q.front()), Q.pop();
        return ans;
    }   
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMinHeightTrees(4, {{1,0}, {1,2}, {1,3}});
    cout << sol.findMinHeightTrees(6, {{0,3}, {1,3}, {2,3}, {4,3}, {5,4}});
    cout << sol.findMinHeightTrees(1, {});
    return 0;
}
