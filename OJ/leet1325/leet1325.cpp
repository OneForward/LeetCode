/*
leet1325


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        function<void(TreeNode*&)> f = [&](TreeNode*& root) {
            if (not root) return;
            f(root->left);
            f(root->right);
            if (not root->left and not root->right and root->val == target) root = {};
        };

        f(root);

        return root;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.removeLeafNodes( toTree({1,2,3,2,null,2,4}), 2) << endl;
    cout << sol.removeLeafNodes( toTree({1,3,3,3,2}), 3) << endl;
    cout << sol.removeLeafNodes( toTree({1,2,null,2,null,2}), 2) << endl;
    cout << sol.removeLeafNodes( toTree({1,1,1}), 1) << endl;
    cout << sol.removeLeafNodes( toTree({1,2,3}), 1) << endl;
    return 0;
}
