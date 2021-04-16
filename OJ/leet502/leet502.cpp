/*
leet502


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
    int findMaximizedCapital1(int k, int W, const vector<int>& Profits, const vector<int>& Capital) {
        // O(N log N), 80ms, 60%
        // 优先队列 + 二叉树
        using Pair = pair<int, int>;
        priority_queue<Pair, vector<Pair>, greater<Pair>> Q;
        multiset<int> tree;
        for (size_t i = 0; i < Profits.size(); i++)
        {
            Q.push({Capital[i], Profits[i]});
        }


        while (k--) {
            while (Q.size()) {
                auto [c, v] = Q.top();
                if (c > W) break;
                Q.pop(); tree.insert(v);
            }
            if (tree.empty()) break;
            W += *tree.rbegin();
            tree.erase(--tree.rbegin().base());
        }
        return W;
    }
    int findMaximizedCapital(int k, int W, const vector<int>& Profits, const vector<int>& Capital) {
        // O(N log N), 56ms, 83%
        // 优先队列 
        int ci = 0, N = Capital.size();

        priority_queue<int> Q;
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return Capital[i] < Capital[j];
        }) ;

        while (k--) {
            while (ci < N and Capital[indices[ci]] <= W) {
                Q.push(Profits[indices[ci]]);
                ci++;
            }
            if (Q.empty()) break;
            W += Q.top(); Q.pop();
        }
        return W;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMaximizedCapital(2, 0, {1,2,3}, {0, 1, 1}) << endl;
    cout << sol.findMaximizedCapital(1, 0, {1,2,3}, {1, 1, 2}) << endl;
    return 0;
}
