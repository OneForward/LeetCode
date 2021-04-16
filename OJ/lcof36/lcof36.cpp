/*
lcof36


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:

    TreeNode* treeToDoublyList(TreeNode* root) {
        if (not root) return {};
        
        TreeNode* prev = {}, *head;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (not root) return ;
            dfs(root->left); 
            if (prev) prev->right = root, root->left = prev;
            else head = root;
            prev = root;
            dfs(root->right); 
        };

        dfs(root);
        head->left = prev; prev->right = head;
        return head;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto head = sol.treeToDoublyList( toTree({4,2,5,1,3}) );
    return 0;
}
