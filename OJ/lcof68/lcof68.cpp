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
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root) return false;
        auto lft = dfs(root->left, p, q), rht =  dfs(root->right, p, q);
        if ((lft and rht) or  ((root == p or root == q) and (lft or rht))) ans = root;

        return lft or rht or root == p or root == q;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto tree = toTree({3,5,1,6,2,0,8,null,null,7,4});
    cout << sol.lowestCommonAncestor( tree, tree->left->left, tree->left->right->left) << endl;
    return 0;
}
