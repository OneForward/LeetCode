/*
lcof68


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, vector<TreeNode*>& v) {
        if (not root) return false;

        v.push_back(root);
        if (root == p) return true;

        if (dfs(root->left, p, v) or dfs(root->right, p, v)) return true;

        v.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;
        dfs(root, p, vp);
        dfs(root, q, vq);

        int i = 0, n = min(vp.size(), vq.size());
        for ( ; i < n and vp[i] == vq[i]; ++i) ;
        return vp[i-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto tree = toTree({3,5,1,6,2,0,8,null,null,7,4});
    cout << sol.lowestCommonAncestor( tree, tree->left->left, tree->left->right->left) << endl;
    return 0;
}
