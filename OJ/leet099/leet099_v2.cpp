
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
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
// vector<int> tree = { 1,3,null,null,2 };
vector<int> tree = { 5,3,9,-2,2 };
// vector<int> tree = { 3,1,4,null,null,2 };

void insert(TreeNode*& root, int i) {
    if (i >= tree.size() || tree[i] == null) return;
    root = new TreeNode(tree[i]);
    insert(root->left, 2*i+1);
    insert(root->right, 2*i+2);
}

void disp(TreeNode* root) {
    if (root == nullptr) {  printf("nullptr, "); return; }
    
    disp(root->left);
    printf("%d, ", root->val);
    disp(root->right);
}

// O(N) 的额外空间

using NodePtr = TreeNode*;

void insertVec(NodePtr root, NodePtr& prev, NodePtr& p1, NodePtr& p2) {
    if (root == nullptr) return;
    insertVec(root->left, prev, p1, p2);
    if (!prev) prev = root;
    if (!p1 && root->val < prev->val) p1 = prev;
    if (!p2 && p1 && root->val > p1->val) p2 = prev;
    if (p1 && p2) return;
    prev = root;
    insertVec(root->right, prev, p1, p2);
}

class Solution {
public:
    void recoverTree(NodePtr root) {
        NodePtr p1{}, p2{}, prev{};
        insertVec(root, prev, p1, p2);
        if (!p2) p2 = prev;
        swap(p1->val, p2->val);
    }
};

int main(int argc, char const *argv[])
{

    TreeNode* root;  insert(root, 0);

    disp(root); printf("\n");

    Solution sol;
    sol.recoverTree(root); printf("\n");

    disp(root); printf("\n");
    return 0;
}
