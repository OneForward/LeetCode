/*
leet865


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (not root) return {};

        function<TreeNode*(TreeNode*, int&)> f = [&](TreeNode* root, int& h) {
            if (not root) return root;
            int lh = 0, rh = 0;
            auto lft = f(root->left, lh);
            auto rht = f(root->right, rh);
            h = max(lh, rh) + 1;
            if (lh < rh) return rht;
            if (lh > rh) return lft;
            return root;
        };

        int h = 0;
        return f(root, h);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.subtreeWithAllDeepest( toTree({})) << endl;
    cout << sol.subtreeWithAllDeepest( toTree({3,5,1,6,2,0,8,null,null,7,4})) << endl;
    cout << sol.subtreeWithAllDeepest( toTree({1})) << endl;
    cout << sol.subtreeWithAllDeepest( toTree({0,1,3,null,2})) << endl;
    
    return 0;
}
