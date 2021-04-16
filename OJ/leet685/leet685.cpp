/*
leet685
并查集

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
    vector<int> P;
    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }
    void merge(int ri, int rj) {
        if (P[ri] < P[rj])  P[ri] += P[rj], P[rj] = ri;
        else  P[rj] += P[ri], P[ri] = rj;
    }

    bool isloop(const vector<int> P, int start) {
        int x = start;
        while (x != -1) {
            x = P[x];
            if (x == start) return true;
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges) { 
        // 并查集
        int n = edges.size()+1;

        vector<int> Q(n, -1);
        int child = -1, pa1 = -1, pa2 = -1;
        for (const auto& edge: edges) { 
            if (Q[edge[1]] < 0) Q[edge[1]] = edge[0];
            else { // double parent
                child = edge[1]; pa1 = Q[edge[1]];
                pa2 = edge[0]; 
            }
        }
        if (child != -1) { // child 出来两条父边
            Q[child] = pa1;
            if (isloop(Q, child)) return {pa1, child};
            // 先出现的那条父边不构成环，则答案一定是后来的那条边
            return {pa2, child};
        }
        
        // start from root, 可以当成无向图处理

        P = vector<int>(n, -1);
        for (const auto& edge: edges) { 
            int ri = find(edge[0]), rj = find(edge[1]);
            if (ri == rj) return edge;
            merge(rj, ri);
        }
        return {};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findRedundantDirectedConnection({{1,2}, {1,3}, {2,3}});
    cout << sol.findRedundantDirectedConnection({{1,2}, {2,3}, {3,4}, {4,1}, {1,5}});
    cout << sol.findRedundantDirectedConnection({{2,1},{3,1},{4,2},{1,4}});
    cout << sol.findRedundantDirectedConnection({{5,2},{5,1},{3,1},{3,4},{3,5}});
    return 0;
}
