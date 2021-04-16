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

        auto prev = [](TreeNode* root) {
            auto prev = root->left;
            if (not prev) return prev;
            while (prev->right) prev = prev->right;
            return prev;
        };

        auto next = [](TreeNode* root) {
            auto next = root->right;
            if (not next) return next;
            while (next->left) next = next->left;
            return next;
        };

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (not root) return ;
            auto left = prev(root), right = next(root);
            dfs(root->right);
            dfs(root->left); 
            
            root->right = right; if (right) right->left = root;
            root->left = left; if (left) left->right = root;
        };

        dfs(root);

        auto head = root, tail = root;
        while ( head->left) head = head->left;
        while ( tail->right) tail = tail->right;
        head->left = tail; tail->right = head;
        return head;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    auto head = sol.treeToDoublyList( toTree({4,2,5,1,3}) );
    return 0;
}
