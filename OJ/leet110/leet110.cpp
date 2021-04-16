/*
leet110


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

class Solution1 {
public:
    int isBalanced(TreeNode* root, bool& ans) {
        if (root == nullptr) return 0;
        int lft = isBalanced(root->left, ans);
        int rht = isBalanced(root->right, ans);
        if (abs(lft - rht) > 1) ans = false;
        return max(lft, rht) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // 20ms
        bool ans = true;
        isBalanced(root, ans);
        return ans;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root, int& depth) {
        if (root == nullptr) { depth = -1; return true;}
        
        int lft, rht; 
        if (isBalanced(root->left, lft) && isBalanced(root->right, rht) && abs(lft - rht) <= 1) {
            depth = max(lft, rht) + 1;
            return true;
        }
        return false;
    }

    bool isBalanced(TreeNode* root) {
        // 16ms
        int depth;
        return isBalanced(root, depth);
    }
};

int main(int argc, char const *argv[])
{    
    // vector v = { 5,4,1,null,1,null,4,2,null,2,null };
    vector v = { 3,9,20,null,null,15,7 };
    // vector v = { 1,2,2,3,3,null,null,4,4 };
    TreeNode* tree = from(v); disp(tree);
    
    Solution sol;   
    cout << boolalpha << sol.isBalanced(tree) << endl;
    return 0;
}
