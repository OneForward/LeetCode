/*
leet378


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
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int kthSmallest(const vector<vector<int>>& M, int k) {
        // 合并 N 个有序链表, O(K log N)
        struct Pair
        {
            int row, col;
        };
        auto cmp = [&](const Pair& p1, const Pair& p2) {
            return M[p1.row][p1.col] > M[p2.row][p2.col];
        };

        priority_queue Q(cmp, vector<Pair>{});

        int n = M.size();
        for (int row = 0; row < n; ++row) Q.push({row, 0});
        while (--k) {
            auto [row, col] = Q.top(); Q.pop();
            if (col < n-1) Q.push({row, col+1});
        }
        auto [row, col] = Q.top();
        return M[row][col];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthSmallest({{1,5,9},{10,11,13},{12,13,15}}, 8) << endl;
    cout << sol.kthSmallest({{-5}}, 1) << endl;
    return 0;
}
