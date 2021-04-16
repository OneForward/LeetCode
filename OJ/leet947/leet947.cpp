/*
leet947
# NOTE: 推荐

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

inline int myhash(const int x, const int y) { return x * 1e4 + y; }

class Solution {
public:
    unordered_map<int, int> P;
    int find(int i) {
        if (P.count(i) == 0) { P[i] = -1; return i; }
        else if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }
    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;
        if (P[ri] < P[rj])  P[ri] += P[rj], P[rj] = ri;
        else  P[rj] += P[ri], P[ri] = rj;
    }
    
    int removeStones(const vector<vector<int>>& stones) {
        int n = stones.size();
        P.clear();

        for (const auto& pos: stones) {
            merge(pos[0]+10001, pos[1]);
        }

        int loops = 0;
        for (const auto& [node, val]: P) {
            if (val < 0) loops++;
        }
        return n-loops;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeStones({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}) << endl;
    cout << sol.removeStones({{0,0},{0,2},{1,1},{2,0},{2,2}}) << endl;
    cout << sol.removeStones({{0,0}}) << endl;
    cout << sol.removeStones({{0,1}, {1,1}}) << endl;
    cout << sol.removeStones({{0,0},{0,1},{1,0},{1,1},{2,1},{2,2},{3,2},{3,3},{3,4},{4,3},{4,4}}) << endl;
    return 0;
}
