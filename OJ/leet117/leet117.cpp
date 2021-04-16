/*
leet117


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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

using TreeNode = Node;

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

void disp2(TreeNode* root) {
    while (root) {
        TreeNode* p = root;
        while (p) {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << "null, \n";
        while (root) {
            if (root->left) {root = root->left; break;}
            else if (root->right) { root = root->right; break;}
            else root = root->next;
        }
    }
}

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        if (root->left == nullptr && root->right == nullptr) return root;
        if (root->left) root->left->next = root->right;
        if (root->next) {
            Node* next = root->next;
            while (next && next->left == nullptr && next->right == nullptr) next = next->next;
            if (next) {
                if (next->left == nullptr) next = next->right;
                else next = next->left;
            }

            if (root->right == nullptr) root->left->next = next;
            else root->right->next = next;
        }
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};


int main(int argc, char const *argv[])
{
    vector v = {2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7};
    TreeNode* t = from(v); disp(t);
    Solution sol;   
    sol.connect(t);
    disp2(t);
    return 0;
}
