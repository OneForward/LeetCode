/*
leet095


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

TreeNode* from(const vector<int>& v, int start = 0) {
    if (start >= v.size() || v[start] == null) return nullptr;

    TreeNode* root = new TreeNode(v[start]);
    root->left = from(v, start*2+1);
    root->right = from(v, start*2+2);
    return root;
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
    vector<TreeNode*> generateTrees(int n, int start) {
        if (n < start) return {nullptr};
        if (n == start) return {new TreeNode(n)};

        vector<TreeNode*> ans;
        for (int i = start; i <= n; ++i) {
            auto lfts = generateTrees(i-1, start);
            auto rhts = generateTrees(n, i+1);
            for (auto lft: lfts) {
                for (auto rht: rhts) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lft;
                    root->right = rht;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        // 16ms, 92%
        if (n == 0) return {};
        return generateTrees(n, 1);
    }
};


int main(int argc, char const *argv[])
{
    // vector v = { 10,5,15,null,null,6,20 };
    // vector v = { 1,1 };
    // vector v = { 2,1,3 };
    // TreeNode* tree = from(v);
    

    Solution sol; 

    auto ans = sol.generateTrees(3);

    for (auto tree: ans) disp(tree); 
    
    return 0;
}
