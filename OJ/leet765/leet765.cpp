/*
leet765


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

class Solution {
public:
    vector<int> P;
    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;
        if (P[ri] < P[rj]) P[ri] += P[rj], P[rj] = ri;
        else P[rj] += P[ri], P[ri] = rj;
    }
    int minSwapsCouples(const vector<int>& row) {
        // O(N), 并查集
        int n = row.size() / 2;
        P = vector<int>(n, -1);
        using Pair = pair<int, int>;
        vector<vector<int>> Q(n); // Q 存储结点位置，构造环图, Q[pos] = {i, j};
        for (int i = 0; i < n; ++i) { 
            Q[row[2*i]/2].push_back(i);
            Q[row[2*i+1]/2].push_back(i);
        }

        for (const auto& q: Q) { 
            merge(q[0], q[1]);
        }

        int loops = 0;
        for (const auto p: P) { 
            if (p < 0) loops++;
        }
        return n - loops;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minSwapsCouples({0, 2, 1, 3}) << endl;
    cout << sol.minSwapsCouples({3, 2, 0, 1}) << endl;
    return 0;
}
