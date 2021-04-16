/*
leet889


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
    TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post) {
        return constructFromPrePost(pre, post, 0, 0, post.size());
    }

    TreeNode* constructFromPrePost(const vector<int>& pre, const vector<int>& post, int lft1, int lft2, int len) {
        if (len == 0) return {};
        
        auto root = new TreeNode(pre[lft1]); lft1++;
        if (len == 1) return root;

        auto lenlft = 0;
        int x = 0, y = 0;
        while (true) {
            x |= (1 << pre[lft1 + lenlft]);
            y |= (1 << post[lft2 + lenlft]);
            lenlft++;
            if (x == y)  break;
            // if (x == y and pre[lft1] == post[lft2 + lenlft - 1])  break;
        }
        root->left = constructFromPrePost(pre, post, lft1, lft2, lenlft);
        root->right = constructFromPrePost(pre, post, lft1+lenlft, lft2+lenlft, len-lenlft-1);
        return root;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.constructFromPrePost({1,2,4,5,3,6,7}, {4,5,2,6,7,3,1}) << endl;
    return 0;
}
