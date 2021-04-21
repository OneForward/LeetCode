/*
leet787


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


class Solution {
public:
    int findCheapestPrice(int N, const vector<vector<int>>& flights, int src, int dst, int K) {
        // Bellman-Ford 松弛算法 O(KN)
        int cost[105], oldcost[105];

        auto relax = [&](int u, int v, int w) {
            cost[v] = min(cost[v], oldcost[u] + w);
        };

        for (int i = 0; i < N; i++) cost[i] = oldcost[i] = INT_MAX / 2;

        oldcost[src] = 0;
        
        for (int k = 0; k <= K; k++)
        {
            for (auto&& e: flights) {
                auto u = e[0], v = e[1], w = e[2];
                relax(u, v, w);
            }
            memcpy(oldcost, cost, sizeof cost);
        }
        
        return cost[dst] == INT_MAX / 2 ? -1 : cost[dst];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findCheapestPrice(3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 1) << endl;
    cout << sol.findCheapestPrice(3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 0) << endl;
    cout << sol.findCheapestPrice(4, {{0,1,1},{0,2,5},{1,2,1},{2,3,1}}, 0, 3, 1) << endl;
    cout << sol.findCheapestPrice(5, {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}}, 0, 2, 2) << endl;
    return 0;
}
