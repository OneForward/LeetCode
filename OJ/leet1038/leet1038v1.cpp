/*
leet1038


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        function<int(TreeNode*, int)> f = [&](TreeNode* root, int sum=0) {
            if (not root) return sum;
            sum = root->val += f(root->right, sum);
            return f(root->left, sum);
        };

        f(root, 0);
        return root;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.bstToGst( toTree({ 4,1,6,0,2,5,7,null,null,null,3,null,null,null,8 }) ) << endl;
    cout << sol.bstToGst( toTree({ 0,null,1 }) ) << endl;
    cout << sol.bstToGst( toTree({ 1,0,2 }) ) << endl;
    cout << sol.bstToGst( toTree({ 3,2,4,1 }) ) << endl;
    return 0;
}
