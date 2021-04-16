/*
leet105


*/


#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    unordered_map<int, int> M;

    TreeNode* buildTree(vector<int>& porder, vector<int>& iorder, int plft, int prht, int ilft, int ilen) {
        if (ilen == 0) return nullptr;

        TreeNode* root = new TreeNode(porder[ilft]);
        int pos = M[porder[ilft]], len_lft = pos - plft, len_rht = prht - pos - 1;
        root->left  = buildTree(porder, iorder, plft,  pos,  ilft+1,         len_lft);
        root->right = buildTree(porder, iorder, pos+1, prht, ilft+len_lft+1, len_rht);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 20ms, Time O(N) 
        int n = preorder.size();
        for (int i = 0; i < n; ++i) M[inorder[i]] = i;
        return buildTree(preorder, inorder, 0, n, 0, n);
    }
};

int main(int argc, char const *argv[])
{
    vector preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};

    Solution sol;   
    auto ans = sol.buildTree(preorder, inorder); disp(ans);

    return 0;
}
