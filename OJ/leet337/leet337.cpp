/*
leet337


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


class Solution1 {
public:
    int dfs1(TreeNode* root) {
        // root is robbed
        return root ? root->val + dfs2(root->left) + dfs2(root->right) : 0;
    }
    int dfs2(TreeNode* root) {
        // root is skipped
        return root ? max(dfs1(root->left), dfs2(root->left)) +
                      max(dfs1(root->right), dfs2(root->right))  : 0;
    }
    int rob(TreeNode* root) {
        // TLE, 朴素的递归解法
        return max(dfs1(root), dfs2(root));
    }
};
class Solution {
public:
    unordered_map<TreeNode*, int> M1;
    unordered_map<TreeNode*, int> M2;
    int dfs1(TreeNode* root) {
        // root is robbed
        auto p = M1.find(root);
        if (p != M1.end()) return p->second;
        M1[root] = root ? root->val + dfs2(root->left) + dfs2(root->right) : 0;
        return M1[root];
    }

    int dfs2(TreeNode* root) {
        // root is skipped
        auto p = M2.find(root);
        if (p != M2.end()) return p->second;
        M2[root] = root ? max(dfs1(root->left), dfs2(root->left)) +
                      max(dfs1(root->right), dfs2(root->right))  : 0;
        return M2[root];
    }
    int rob(TreeNode* root) {
        // 44ms, 自顶向下的动态规划解法
        M1.clear();
        M2.clear();
        return max(dfs1(root), dfs2(root));
    }
};



struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution2 {
public:
    SubtreeStatus dfs(TreeNode* o) {
        if (!o) {
            return {0, 0};
        }
        auto l = dfs(o->left);
        auto r = dfs(o->right);
        int selected = o->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* o) {
        // 自底向上的动态规划
        auto rootStatus = dfs(o);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.rob( from( {3,2,3,null,3,null,1} ) ) << endl;
    cout << sol.rob( from( {3,4,5,1,3,null,1} ) ) << endl;
    cout << sol.rob( from( { 4,1,null,2,null,3 } ) ) << endl;
    return 0;
}
