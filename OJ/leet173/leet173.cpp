/*
leet173


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

TreeNode* from(vector<int>& v) {
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == null && 2*i+1 < v.size()) v.insert(v.begin()+2*i+1, null);
        if (v[i] == null && 2*i+2 < v.size()) v.insert(v.begin()+2*i+2, null);
    }
    vector<TreeNode*> t(v.size());
    for (int i = v.size()-1; i >= 0; --i) {
        if (v[i] != null) {
            t[i] = new TreeNode(v[i]);
            if (2*i+1 < v.size()) t[i]->left = t[2*i+1];
            if (2*i+2 < v.size()) t[i]->right = t[2*i+2];
        }
    }
    return t[0];
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

// class BSTIterator {
// public:
//     vector<int> v;
//     int index = 0;

//     void inorder(TreeNode* root) {
//         if (root == nullptr) return;
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     BSTIterator(TreeNode* root) {
//         inorder(root);
//     }
    
//     /** @return the next smallest number */
//     int next() {
//         return v[index++];
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         return index < v.size();
//     }
// };

class BSTIterator {
public:
    stack<TreeNode*> S;

    void lft_most_inorder(TreeNode* root) {
        while (root) {
            S.push(root); root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        // 100ms, 使用栈模拟中序遍历过程
        lft_most_inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto p = S.top(); S.pop();
        if (p->right) lft_most_inorder(p->right);
        return p->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
};


int main(int argc, char const *argv[])
{

    vector v = { 7, 3, 15, null, null, 9, 20 };

    TreeNode* t1 = from(v); disp(t1);
    BSTIterator* iter = new BSTIterator(t1);
    while (iter->hasNext()) {
        cout << iter->next() << ", "; 
    }
    return 0;
}