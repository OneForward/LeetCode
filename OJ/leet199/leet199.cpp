/*
leet199


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
    vector<int> rightSideView(TreeNode* root) {
        // 4ms
        if (root == nullptr) return {};

        vector<int> ans; int prev;
        queue<TreeNode*> Q; Q.push(root); Q.push(nullptr); 
        while (Q.size() > 1) {
            auto p = Q.front(); Q.pop();
            if (p == nullptr) Q.push(p), ans.push_back(prev);
            else {
                prev = p->val;
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            }
        }
        ans.push_back(prev);
        return ans;
    }
};


int main(int argc, char const *argv[])
{

    // vector v = { 10,5,15,null,null,6,20 };
    // vector v = { 1,2,3,null,5,null,4 };
    vector v = { 1, null, 2 };
    // vector v = { 1 , 2, 3, 4 };
    TreeNode* t1 = from(v); disp(t1);
    
    Solution sol;
    auto ans = sol.rightSideView(t1);
    for (auto vi: ans) cout << vi << ", "; cout << endl;
    return 0;
}
