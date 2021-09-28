/*
leet437


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

TreeNode* from(const vector<int>& vs) {
    vector<int> v = vs;
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
    int cnt;
    int target;

    void dfsInherit(TreeNode* root, int sum) {
        if (root == nullptr) return;

        auto newsum = sum + root->val;
        if (newsum == target) cnt++;

        dfsInherit(root->left, newsum);
        dfsInherit(root->right, newsum);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        if (root->val == target) cnt++;
        dfsInherit(root->left, root->val);
        dfsInherit(root->right, root->val);

        dfs(root->left);
        dfs(root->right);
    }

    int pathSum(TreeNode* root, int sum) {
        // 24ms, 递归套递归 
        target = sum; cnt = 0;
        dfs(root);
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.pathSum( from( {10,5,-3,3,2,null,11,3,-2,null,1}), 8 ) << endl;
    cout << sol.pathSum( from( {1,null,2,null,3,null,4,null,5} ), 3) << endl;
    cout << sol.pathSum( from( {1}),  1) << endl;
    return 0;
}
