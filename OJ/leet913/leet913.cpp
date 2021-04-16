/*
leet913


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


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
class Solution {
public:
    enum STATE{ DRAW, MOUSE_WIN, CAT_WIN } ;

    int n;
    VVVI f;

    int dfs(const VVI& graph, int x, int y, int t) {
        // x: mouse pos, y : cat pos, t: timestamp
        if (t == 2*n) return DRAW;
        if (x == y) return f[t][x][y] = CAT_WIN;
        if (x == 0) return f[t][x][y] = MOUSE_WIN;

        if (f[t][x][y] >= 0) return f[t][x][y];

        if (t % 2 == 0) {
            // Mouse Step
            auto catWin = true;
            for (auto xneighbor: graph[x]) {
                auto next = dfs(graph, xneighbor, y, t+1);
                if (next == MOUSE_WIN) return f[t][x][y] = MOUSE_WIN;
                if (next == DRAW) catWin = false; // at least mouse can go someplace, cat can't win
            }
            if (catWin) return f[t][x][y] = CAT_WIN; 
            else return f[t][x][y] = DRAW;
        }
        else {
            // Cat Step
            auto mouseWin = true;
            for (auto yneighbor: graph[y]) {
                if (yneighbor == 0) continue; // cat can't go to 0
                auto next = dfs(graph, x, yneighbor, t+1);
                if (next == CAT_WIN) return f[t][x][y] = CAT_WIN;
                if (next == DRAW) mouseWin = false;
            }
            if (mouseWin) return f[t][x][y] = MOUSE_WIN; 
            else return f[t][x][y] = DRAW;
        }
    }
    int catMouseGame(const VVI& graph) {
        n = graph.size();
        f.resize(2*n, VVI(n, VI(n, -1)));
        
        return dfs(graph, 1, 2, 0);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.catMouseGame({{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}}) << endl;
    return 0;
}
