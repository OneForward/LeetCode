/*
leet450


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
        auto tree = TreeNode{{}, root, {}};
        auto parent = &tree, cur = root; 

        while (cur) {
            if ( key < cur->val) parent = cur, cur = cur->left;
            else if ( key > cur->val) parent = cur, cur = cur->right;
            else break;
        }
        if (not cur) return root; // not found

        // found deletion-node
        if (cur->left and cur->right) { // two-child
            // let's find successor
            auto backup = cur;
            parent = cur;  cur = cur->right; 
            while (cur and cur->left ) {
                parent = cur; cur = cur->left;
            }
            backup->val = cur->val; 
            // now cur has at most one-child
        }

        auto replace_node = cur->left ? cur->left : cur->right;

        if (parent->left == cur) parent->left = replace_node;
        else parent->right = replace_node;

        // delete cur;
        return tree.left;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.deleteNode( toTree({5,3,6,2,4,null,7}), 3 ) << endl;
    cout << sol.deleteNode( toTree({5,3,6,2,4,null,7}), 0 ) << endl;
    cout << sol.deleteNode( toTree({}), 0 ) << endl;
    return 0;
}
