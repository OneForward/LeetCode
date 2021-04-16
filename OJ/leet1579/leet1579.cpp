/*
leet1579

并查集，贪心

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

static int deleted = 0;

struct UnionFindSet
{
    
    vector<int> P;
    int trees;

    UnionFindSet(int n): P(n+1, -1), trees(n) {}
    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    void merge(const vector<int>& edge) {
        int ri = find(edge[1]), rj = find(edge[2]);
        if (ri == rj) { deleted++; return; }
        if (P[ri] < P[rj]) swap(ri, rj);
        P[rj] += P[ri]; P[ri] = rj; trees--;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, const vector<vector<int>>& edges) {
        // 并查集，贪心
        // 优先选择 type3 的边构造树，然后分别对 Alice 和 Bob 建树去边即可
        // ：边数最少的连通图必定是树

        UnionFindSet SAlice(n);  deleted = 0;
        for (const auto& edge: edges) {
            if (edge[0] != 3) continue;
            SAlice.merge(edge);
        }

        UnionFindSet SBob = SAlice;
        for (const auto& edge: edges) {
            if (edge[0] == 1) SAlice.merge(edge);
            else if (edge[0] == 2) SBob.merge(edge);
        }
        return (SAlice.trees == 1 &&
                SBob.trees == 1) ? deleted : -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxNumEdgesToRemove(4, {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}}) << endl;
    cout << sol.maxNumEdgesToRemove(4, {{3,1,2},{3,2,3},{1,1,4},{2,1,4}}) << endl;
    cout << sol.maxNumEdgesToRemove(4, {{1,1,2},{3,2,3},{2,3,4}}) << endl;
    return 0;
}
