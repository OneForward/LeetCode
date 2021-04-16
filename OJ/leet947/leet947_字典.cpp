/*
leet947


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
    void merge(int ri, int rj) {
        if (P[ri] < P[rj])  P[ri] += P[rj], P[rj] = ri;
        else  P[rj] += P[ri], P[ri] = rj;
    }
    
    int removeStones(const vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> X, Y;
        for (const auto& pos: stones) {
            X[pos[0]].push_back(pos[1]);
            Y[pos[1]].push_back(pos[0]);
        }

        P.clear();
        for (const auto& [x, ys]: X) {
            for (const auto y: ys) {
                auto ri = find(myhash(x, ys[0]));
                auto rj = find(myhash(x, y));
                if (ri != rj) 
                    merge(ri, rj);
            }
        }
        for (const auto& [y, xs]: Y) {
            for (const auto x: xs) {
                auto ri = find(myhash(xs[0], y));
                auto rj = find(myhash(x, y));
                if (ri != rj) 
                    merge(ri, rj);
            }
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
