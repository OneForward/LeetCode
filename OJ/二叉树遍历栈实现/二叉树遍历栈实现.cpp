/*
二叉树遍历栈实现


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

namespace Recusive
{
    vector<int> preOrder(TreeNode* root) {
        vector<int> v;

        function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (root == nullptr) return;
            v.push_back(root->val);
            f(root->left);
            f(root->right);
        };
        
        f(root);
        return v;
    }

    vector<int> inOrder(TreeNode* root) {
        vector<int> v;

        function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (root == nullptr) return;
            f(root->left);
            v.push_back(root->val);
            f(root->right);
        };
        
        f(root);
        return v;
    }
    
    vector<int> postOrder(TreeNode* root) {
        vector<int> v;

        function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (root == nullptr) return;
            f(root->left);
            f(root->right);
            v.push_back(root->val);
        };
        
        f(root);
        return v;
    }
};

namespace Stack
{
    vector<int> preOrder(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> S; S.push(root);

        while (S.size()) {
            auto root = S.top(); S.pop();
            if (root) {
                if (root->right) S.push(root->right);
                if (root->left) S.push(root->left);
                S.push(root); S.push(nullptr); 
            }
            else {
                v.push_back(S.top()->val); S.pop();
            }
        }
        
        return v;
    }

    vector<int> inOrder(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> S; S.push(root);

        while (S.size()) {
            auto root = S.top(); S.pop();
            if (root) {
                if (root->right) S.push(root->right);
                S.push(root); S.push(nullptr); 
                if (root->left) S.push(root->left);
            }
            else {
                v.push_back(S.top()->val); S.pop();
            }
        }
        
        return v;
    }

    vector<int> postOrder(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> S; S.push(root);

        while (S.size()) {
            auto root = S.top(); S.pop();
            if (root) {
                S.push(root); S.push(nullptr); 
                if (root->right) S.push(root->right);
                if (root->left) S.push(root->left);
            }
            else {
                v.push_back(S.top()->val); S.pop();
            }
        }
        
        return v;
    }


    
} // namespace Stack



int main(int argc, char const *argv[])
{
    prettyPrintTree(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null}));
    // cout << Recusive::preOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    // cout << Stack::preOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    // cout << Recusive::inOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    // cout << Stack::inOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    // cout << Recusive::postOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    // cout << Stack::postOrder(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    return 0;
}
