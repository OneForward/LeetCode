
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
vector<int> tree = { 3,1,4,null,null,2 };

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



// O(n) 的额外空间

void insertVec(vector<TreeNode*>& v, TreeNode* root) {
    if (root == nullptr) return;
    insertVec(v, root->left);
    v.push_back(root);
    insertVec(v, root->right);
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        insertVec(v, root);

        TreeNode* p1{}, *p2{};
        for (int i=1; i<v.size(); ++i) {
            if (!p1 && v[i]->val < v[i-1]->val) { p1 = v[i-1]; continue; }
            if (p1 && v[i]->val > p1->val) { p2 = v[i-1]; break; }
        }
        if (!p2) p2 = v.back();
        
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
