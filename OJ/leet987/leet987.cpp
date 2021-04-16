/*
leet987


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    using Tuple = tuple<int, int, int>;
    vector<Tuple> Q;

    void midOrder(TreeNode* root, int row = 0, int col = 0) {
        if (root == nullptr) return;
        midOrder(root->left, row+1, col-1);
        Q.push_back({col, row, root->val});
        midOrder(root->right, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // O(N log N), 8ms
        Q.clear(); 
        
        midOrder(root);

        sort(Q.begin(), Q.end());

        vector<vector<int>> ans; int prevCol = -1e5;
        for (const auto& [col, row, val]: Q) {
            if (col == prevCol) ans.back().push_back(val);
            else ans.push_back({val});
            prevCol = col;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.verticalTraversal(toTree({3,9,20,null, null, 15, 7})) << endl;
    // cout << sol.verticalTraversal(toTree({1,2,3,4,5,6,7})) << endl;
    // cout << sol.verticalTraversal(toTree({1,2,3,4,6,5,7})) << endl;
    cout << sol.verticalTraversal(toTree({0,10,1,null,null,2,4,3,5,null,null,6,null,7,9,8,null,null,null,null,11,null,null,12})) << endl;

    return 0;
}
