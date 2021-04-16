/*
leet124


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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
    int f(TreeNode* root) {
        if (root == nullptr) return 0;
        int lftMax = f(root->left),
            rhtMax = f(root->right);
        ans = max(ans, root->val + lftMax + rhtMax);
        return max(0, max(lftMax, rhtMax) + root->val);
    }
};


int main(int argc, char const *argv[])
{
    
    Solution sol;   
    cout << sol.maxPathSum(from({1,2,3})) << endl;
    cout << sol.maxPathSum(from({-10,9,20,null,null,15,7})) << endl;
    cout << sol.maxPathSum(from({5,4,8,11,null,13,4,7,2,null,null,null,1})) << endl;
    return 0;
}
