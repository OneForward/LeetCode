/*
leet145


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    vector<int> v;
    void f(TreeNode* root) {
        if (root == nullptr) return;
        
        f(root->left); 
        f(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return v;
    }
};


class Solution2 {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        // 官方解法，倒序输出
        if (root == nullptr) return {};

        stack<TreeNode*> S; S.push(root);
        while (!S.empty()) {
            auto p = S.top(); v.push_back(p->val); S.pop();
            if (p->left) S.push(p->left);
            if (p->right) S.push(p->right);
            
        }
        return vector<int>(v.rbegin(), v.rend());
    }
};

class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        // 栈迭代, 后序遍历
        stack<TreeNode*> S; 
        if (root) S.push(root); 
        while (!S.empty()) {
            auto p = S.top(); S.pop();
            if (p) {
                S.push(p); S.push(nullptr);
                if (p->right) S.push(p->right);
                if (p->left) S.push(p->left);
            }
            else {
                v.push_back( S.top()->val );
                S.pop();
            }
            
            
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.postorderTraversal(toTree({1,2,3,null,null,4,5,null,6,7,null,8,null})) << endl;
    return 0;
}
