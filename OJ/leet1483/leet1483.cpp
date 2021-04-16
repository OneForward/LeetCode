/*
leet1483


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

// 倍增法， Sparse Table 法， Binary Lifting, 动态规划
// query O(log N)
// f[node][j] 保存的是 node 距离为 2^j 的祖先
// 递推关系 f[node][j] : newnode =  f[node][j-1] -> f[newnode][j-1]
class TreeAncestor {
public:
    vector<vector<int>> f;

    TreeAncestor(int n, const vector<int>& parent) {
        f = vector<vector<int>>(n, vector<int>(17));
        for (size_t node = 0; node < n; node++)
        {
            f[node][0] = parent[node];
        }

        for (size_t j = 1; j < 17; j++)
        {
            for (size_t node = 0; node < n; node++)
            {
                auto newnode = f[node][j-1];
                f[node][j] = newnode == -1 ? -1 : f[newnode][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        auto pos = 0;
        while (k) {
            if (k & 1) node = f[node][pos];
            if (node == -1) break;
            pos++; k >>= 1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


int main(int argc, char const *argv[])
{
    // TreeAncestor tree(7, {-1,0,0,1,1,2,2});
    // cout << tree.getKthAncestor(3, 1) << endl;
    // cout << tree.getKthAncestor(5, 2) << endl;
    // cout << tree.getKthAncestor(6, 3) << endl;
    TreeAncestor tree(10, {-1,0,0,1,2,0,1,3,6,1});
    cout << tree.getKthAncestor(8, 6) << endl;
    cout << tree.getKthAncestor(9, 7) << endl;
    cout << tree.getKthAncestor(1, 1) << endl;
    cout << tree.getKthAncestor(2, 5) << endl;
    cout << tree.getKthAncestor(4, 2) << endl;
    cout << tree.getKthAncestor(7, 3) << endl;
    cout << tree.getKthAncestor(3, 7) << endl;
    cout << tree.getKthAncestor(9, 6) << endl;
    cout << tree.getKthAncestor(3, 5) << endl;
    cout << tree.getKthAncestor(8, 8) << endl;
    return 0;
}
