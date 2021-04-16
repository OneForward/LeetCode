/*
leet1489

切记： 多用 const auto& !!!!!!!! 不要直接使用 auto !!!!
极度影响时间！！！！

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

struct UnionFindSet
{
    vector<int> P;
    int setCount;

    UnionFindSet(int n): P(n, -1), setCount(n) {}

    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    bool merge(const vector<int>& edge) {
        int ri = find(edge[0]), rj = find(edge[1]);
        if (ri == rj) return false;
            
        if (P[ri] < P[rj]) swap(ri, rj);
        P[rj] += P[ri], P[ri] = rj; setCount--;
        return true;
    }
};


class Solution {
public:
    vector<vector<int>> edges;
    int n;
    int m;
    pair<int, bool> kruscal(int removed, bool check_pseudo=false) {
        UnionFindSet S(n);
        int weight = 0;
        if (check_pseudo) S.merge(edges[removed]), weight += edges[removed][2];
        for (int i = 0; i < edges.size(); ++i) { 
            const auto& edge = edges[i];
            if (i != removed && S.merge(edge))
                weight += edge[2];
        }

        return {weight, S.setCount == 1};
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int _n, const vector<vector<int>>& _edges) {
        edges = _edges; 
        m = edges.size(); n = _n;
        for (int i = 0; i < m; ++i) edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](const vector<int>& lft, const vector<int>& rht) {
            return lft[2] < rht[2];
        });
        
        int weight = kruscal(-1).first;
        
        vector<int> critical, pseuo_critical;
        
        for (int i = 0; i < m; ++i) { 
            { 
                const auto& [wi, isconnected] = kruscal(i);
                if (wi > weight || !isconnected) {
                    critical.push_back(edges[i][3]); continue;
                }
            }
            {
                const auto& [wi, _] = kruscal(i, true);
                if (wi == weight) pseuo_critical.push_back(edges[i][3]);
            }
        }

        return {critical, pseuo_critical};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findCriticalAndPseudoCriticalEdges(5, {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}}) << endl;
    cout << sol.findCriticalAndPseudoCriticalEdges(4, {{0,1,1},{1,2,1},{2,3,1},{0,3,1}}) << endl;
    cout << sol.findCriticalAndPseudoCriticalEdges(6, {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}}) << endl;
    cout << sol.findCriticalAndPseudoCriticalEdges(14, {{0,1,13},{0,2,6},{2,3,13},{3,4,4},{0,5,11},{4,6,14},{4,7,8},{2,8,6},{4,9,6},{7,10,4},{5,11,3},{6,12,7},{12,13,9},{7,13,2},{5,13,10},{0,6,4},{2,7,3},{0,7,8},{1,12,9},{10,12,11},{1,2,7},{1,3,10},{3,10,6},{6,10,4},{4,8,5},{1,13,4},{11,13,8},{2,12,10},{5,8,1},{3,7,6},{7,12,12},{1,7,9},{5,9,1},{2,13,10},{10,11,4},{3,5,10},{6,11,14},{5,12,3},{0,8,13},{8,9,1},{3,6,8},{0,3,4},{2,9,6},{0,11,4},{2,5,14},{4,11,2},{7,11,11},{1,11,6},{2,10,12},{0,13,4},{3,9,9},{4,12,3},{6,7,10},{6,8,13},{9,11,3},{1,6,2},{2,4,12},{0,10,3},{3,12,1},{3,8,12},{1,8,6},{8,13,2},{10,13,12},{9,13,11},{2,11,14},{5,10,9},{5,6,10},{2,6,9},{4,10,7},{3,13,10},{4,13,3},{3,11,9},{7,9,14},{6,9,5},{1,5,12},{4,5,3},{11,12,3},{0,4,8},{5,7,8},{9,12,13},{8,12,12},{1,10,6},{1,9,9},{7,8,9},{9,10,13},{8,11,3},{6,13,7},{0,12,10},{1,4,8},{8,10,2}}) << endl;
    return 0;
}
