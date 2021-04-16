/*
leet100


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 8ms
        if (p == nullptr && q == nullptr) return true;

        if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        return false;
    }
};


int main(int argc, char const *argv[])
{
    vector v1 = { 1,2,3}; TreeNode* t1 = from(v1); disp(t1);
    vector v2 = { 1,null,2,3} ; TreeNode* t2 = from(v2); disp(t2);
    
    Solution sol;   
    cout << boolalpha << sol.isSameTree(t1, t2) << endl;
    return 0;
}
