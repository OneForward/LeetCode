/*
leet129


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
    vector<int> v;
    int x = 0;
    void f(TreeNode* root) {
        x = 10 * x + root->val; 
        if (root->left == nullptr && root->right == nullptr) v.push_back(x);
        
        if (root->left) f(root->left); 
        if (root->right) f(root->right);
        x /= 10;
    }
    int sumNumbers(TreeNode* root) {
        // 4ms
        if (root == nullptr) return 0;

        f(root);

        int ans = 0;
        for (const auto& vi: v) ans += vi;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector v=  { 4, 9, 0, 5,1 }; 
    auto t = from( v );
    Solution sol;   
    auto ans = sol.sumNumbers(t);
    
    cout << ans << endl;

    return 0;
}
