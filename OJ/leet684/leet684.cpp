/*
leet684


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


// overload for ostream of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

// overload for ostream of vectors of vectors
template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}





class Solution {
public:
    vector<int> P;

    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    void merge(int r1, int r2) { // r1, r2 have to be root
        if (P[r1] < P[r2]) P[r1] += P[r2], P[r2] = r1;
        else P[r2] += P[r1], P[r1] = r2;
    }

    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        P = vector<int>(edges.size()+1, -1);
        for (const auto& edge: edges) {
            int r1 = find(edge[0]), r2 = find(edge[1]);
            if (r1 == r2) return edge;
            merge(r1, r2);
        }
        return {};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findRedundantConnection({{1,2}, {1,3}, {2,3}, }) << endl;
    // cout << sol.findRedundantConnection({{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}) << endl;
    return 0;
}
