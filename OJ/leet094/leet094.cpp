/*
leet094


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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int null = -1;

TreeNode* from(const vector<int>& v, int start = 0) {
    if (start >= v.size() || v[start] == null) return nullptr;

    TreeNode* root = new TreeNode(v[start]);
    root->left = from(v, start*2+1);
    root->right = from(v, start*2+2);
    return root;
}
void disp(TreeNode* root) {
    TreeNode* flag = new TreeNode();
    queue<TreeNode*> Q; Q.push(root); Q.push(flag);
    while (Q.size() > 1) {
        auto p = Q.front(); Q.pop();
        if (p == flag) Q.push(p); 
        else if (p == nullptr) cout << "null, ";
        else {
            cout << p->val << ", ";
            if (p->left == nullptr && p->right == nullptr) continue;
            Q.push(p->left);
            Q.push(p->right);
        } 
    }
    cout << endl; delete flag;
}

class Solution1 {
public:
    vector<int> v;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;
    }
};
class Solution {
public:
    vector<int> v;

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        if (root) S.push(root);

        while ( !S.empty() ) {
            auto p = S.top(); S.pop();
            if (p) {
                if (p->right) S.push(p->right);
                S.push(p); S.push(nullptr);
                if (p->left) S.push(p->left);
            }
            else {
                v.push_back(S.top()->val); S.pop();
            }
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    vector v = { 1,2,3, 4,5,6 };
    TreeNode* tree = from(v); disp(tree);
    
    Solution sol;   
    auto ans = sol.inorderTraversal(tree);
    for (auto vi: ans) cout << vi << ", "; cout << endl;
    return 0;
}
