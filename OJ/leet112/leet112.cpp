/*
leet112


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
    void dfs(TreeNode* root, int sum, int target, bool& ans) {

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) ans = true; return;
        }
        if (root->left) dfs(root->left, sum, target, ans); 
        if (root->right) dfs(root->right, sum, target, ans);
    }
    bool hasPathSum(TreeNode* root, int target) {
        // 12ms
        if (root == nullptr) return false;

        bool ans = false;
        dfs(root, 0, target, ans);
        return ans;
    }
};


class Solution {
public:

    bool hasPathSum(TreeNode* root, int target) {
        // 8ms
        if (root == nullptr) return false;

        target -= root->val;
        if (root->left == nullptr && root->right == nullptr)
            return target == 0;
        
        return hasPathSum(root->left, target) || hasPathSum(root->right, target) ;
    }
};

int main(int argc, char const *argv[])
{
    // vector v = {3,9,20,null,null,15,7 };
    vector v = {1,2 }; int target = 1;
    // vector v=  { 5, 4, 8, 11, 13, 4, 7, 2, null, null, null, 1 }; int target = 22;
    auto t = from( v );
    Solution sol;   
    auto ans = sol.hasPathSum(t, target);
    cout << boolalpha << ans << endl;

    return 0;
}
