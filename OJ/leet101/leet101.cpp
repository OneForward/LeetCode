/*
leet101


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

class Solution1 {
public:
    bool isSymmetric(TreeNode* lft, TreeNode* rht) {
        // 4ms, 递归
        if (lft == nullptr && rht == nullptr) return true;
        if (lft && rht && lft->val == rht->val) {
            return isSymmetric(lft->right, rht->left) && isSymmetric(lft->left, rht->right);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};
class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        // 8ms, 迭代，栈方法
        stack<TreeNode*> Slft, Srht;
        TreeNode* lft = root, *rht = root;
        while (lft || !Slft.empty()) {
            while (lft) {
                if (rht == nullptr || lft->val != rht->val) return false;
                Slft.push(lft); Srht.push(rht);
                lft = lft->left; rht = rht->right;
            }
            lft = Slft.top(); Slft.pop();
            rht = Srht.top(); Srht.pop();
            lft = lft->right; rht = rht->left;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{    
    // vector v = { 1,2,2,3,4,4,3 };
    // vector v = { 1,2,2,null,3,null,3 };
    // vector v = { 1,2,2,2,null,2 };
    vector v = { 5,4,1,null,1,null,4,2,null,2,null };
    TreeNode* tree = from(v); disp(tree);
    
    Solution sol;   
    cout << boolalpha << sol.isSymmetric(tree) << endl;
    return 0;
}
