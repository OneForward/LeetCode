/*
leet1319
并查集

*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

struct UnionFindSet
{
    vector<int> P;
    int trees;
    
    UnionFindSet(int n): P(n, -1), trees(n) {}

    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;

        if (P[ri] < P[rj]) swap(ri, rj);
        // rj as root
        P[rj] += P[ri]; P[ri] = rj; trees--;
    }

};



class Solution {
public:

    int makeConnected(int n, vector<vector<int>> connections) {
        int m = connections.size();
        if (m < n-1) return -1;
        
        UnionFindSet S(n);
        for (const auto& edge: connections) {
            S.merge(edge[0], edge[1]);
        }
        return S.trees - 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.makeConnected(4, {{0,1},{0,2},{1,2}}) << endl;
    cout << sol.makeConnected(6, {{0,1},{0,2},{0,3},{1,2},{1,3}}) << endl;
    cout << sol.makeConnected(12, {{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}}) << endl;
    return 0;
}
