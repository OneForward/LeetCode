#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val; int index;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_demo() {
    TreeNode* arr[15] ; int index = 0;
    for (auto& ptr: arr) 
        ptr = new TreeNode(),
        ptr->index = index++;
    vector<vector<int>> M {{1,2,3}, {2,4,5}, {4,6,7}, 
                           {5,8,9}, {9, 10, 11},
                           {6, 12, 13}};
    for (const auto& m:M) {
        if (m[1] >= 0) arr[m[0]]->left = arr[m[1]];
        if (m[2] >= 0) arr[m[0]]->right = arr[m[2]];
    }
    return arr[1];
}

void print(TreeNode* root) {
    if (root == NULL) return;
    int lft = -1, rht = -1;
    if (root->left) lft = root->left->index;
    if (root->right) rht =  root->right->index;
    printf("%d -> (%d, %d), val: %d\n", root->index, lft, rht, root->val);
    print(root->left);
    print(root->right);
}
int dfs_height(TreeNode* root, int& ans) {
    if (root == NULL) return -1;
    int lft = 0,  rht = 0;
    if (root->left) lft = dfs_height(root->left, ans);
    if (root->right) rht = dfs_height(root->right, ans);
    root->val = lft + rht;
    ans = max(ans, root->val);
    return max(lft, rht) + 1;
}

class Solution {
public:

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs_height(root, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    TreeNode* tree = create_demo();
    print(tree);
    printf("%d\n", sol.diameterOfBinaryTree(tree));
    print(tree);
    return 0;
}
