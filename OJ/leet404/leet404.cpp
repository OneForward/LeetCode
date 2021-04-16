/*
leet404


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
// #include "../utils/LeetCpp.utils.hpp"

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
    void sumOfLeftLeaves(TreeNode* root, bool isleft, int& ans) {
        if (root == nullptr) return ;
        if (isleft && root->left == nullptr && root->right == nullptr) ans += root->val;
        sumOfLeftLeaves(root->left, true, ans);
        sumOfLeftLeaves(root->right, false, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumOfLeftLeaves(root, false, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* t1 = from( {3, 9, 20, null, null, 15, 7} ); // disp(t1);

    Solution sol; 
    cout << sol.sumOfLeftLeaves(t1)   << endl;

    return 0;
}
