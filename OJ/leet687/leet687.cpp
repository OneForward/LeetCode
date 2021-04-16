/*
leet687


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
#include "../utils/LeetCpp.utils.hpp"
using namespace std;


class Solution1 {
public:
    int maxVal = 0;
    pair<int, int> f(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        int lft = 0, rht = 0;
        if (root->left) {
            auto [lval, rval] =  f(root->left); 
            if (root->left->val == root->val) lft = max(lval, rval) + 1;
        }
        if (root->right) {
            auto [lval, rval] =  f(root->right); 
            if (root->right->val == root->val) rht = max(lval, rval) + 1;
        }
        maxVal = max(maxVal, lft + rht + 1);
        return {lft, rht};
    }
    int longestUnivaluePath(TreeNode* root) {
        maxVal = 0;
        f(root);
        return maxVal-1;
    }
};


class Solution {
public:
    int ans;

    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        f(root);
        return ans;
    } 

    int f(TreeNode* root) {
        // f(root) 记录的是以 root 为起点的单边的最长同值路径的长度
        if (root == nullptr) return 0;

        auto lft = f(root->left); // 递归，同时捕获左边最长长度
        if (root->left && root->left->val == root->val) lft++;
        else lft = 0;

        auto rht = f(root->right);
        if (root->right && root->right->val == root->val) rht++;
        else rht = 0;

        ans = max(lft + rht, ans);
        return max(lft, rht);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;  
    cout << sol.longestUnivaluePath( toTree( {} ) ) << endl;
    cout << sol.longestUnivaluePath( toTree( {5,4,5,1,1,null,5} ) ) << endl;
    cout << sol.longestUnivaluePath( toTree( {1, 4, 5, 4, 4, null, 5} ) ) << endl;
    cout << sol.longestUnivaluePath( toTree( { 1,null,1,1,1,1,1,1 } ) ) << endl;
    cout << sol.longestUnivaluePath( toTree( { 5,4,5,4,4,5,3,4,4,null,null,null,4,null,null,4,null,null,4,null,4,4,null,null,4,4 } ) ) << endl;
    return 0;
}
