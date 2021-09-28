/*
leet437


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    unordered_map<int, int> M;

    int f(TreeNode* root, int sum, int targetSum) {
        if (not root) return 0;
        sum += root->val; 
        
        int cnt = 0;
        if (M.find(sum - targetSum) != M.end()) cnt += M[sum - targetSum];

        M[sum]++;
        cnt += f(root->left, sum, targetSum);
        cnt += f(root->right, sum, targetSum);
        M[sum]--;
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        M.clear(); M[0] = 1;
        return f(root, 0, targetSum);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.pathSum( toTree( {10,5,-3,3,2,null,11,3,-2,null,1}), 8 ) << endl;
    cout << sol.pathSum( toTree( {5,4,8,11,null,13,4,7,2,null,null,5,1}), 22 ) << endl;
    cout << sol.pathSum( toTree( {1,null,2,null,3,null,4,null,5} ), 3) << endl;
    cout << sol.pathSum( toTree( {1}),  1) << endl;
    cout << sol.pathSum( toTree( {}),  1) << endl;
    cout << sol.pathSum( toTree( {}),  0) << endl;
    cout << sol.pathSum( toTree( {1}),  0) << endl;
    cout << sol.pathSum( toTree( {0,}),  0) << endl;
    cout << sol.pathSum( toTree( {0,1,1}),  0) << endl;
    
    return 0;
}
