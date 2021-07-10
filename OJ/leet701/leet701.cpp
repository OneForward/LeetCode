/*
leet701


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* f(TreeNode*& root, int val) {
        if (not root) return root = new TreeNode{val};
        if (root->val > val) f(root->left, val);
        else f(root->right, val);
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return f(root, val);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.insertIntoBST(toTree({40,20,60,10,30,50,70}), 25) << endl;
    return 0;
}
