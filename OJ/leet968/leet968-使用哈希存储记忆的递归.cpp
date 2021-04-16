/*
leet968


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

class Solution1 {
public:
    // TLE
    enum STATE { CAMERA, OK, USHOULD };
    int f(TreeNode* root, STATE pstate) { // 
        if (root == nullptr) return 0;
        if (pstate == CAMERA) {
            auto d1 = 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
            auto d2 = f(root->left, OK) + f(root->right, OK);
            return min(d1, d2);
        }
        if (pstate == USHOULD) return 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
        
        // parent is ok
        auto d0 = 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
        int d1 = INT_MAX, d2 = INT_MAX;
        if (root->left) d1 =  f(root->left, USHOULD) + f(root->right, OK);
        if (root->right) d2 = f(root->left, OK) + f(root->right, USHOULD);
        return min(d0, min(d1, d2));
    }

    int minCameraCover(TreeNode* root) {
        return f(root, OK);
    }
};

// 带记忆的递归 16ms, 23.1MB
class Solution {
public:
    struct Tuple
    {
        int states[3] = {-1, -1, -1};
    };
    
    unordered_map<TreeNode*, Tuple> M;
    enum STATE { CAMERA, OK, USHOULD };
    int f(TreeNode* root, int pstate) { // 
        if (root == nullptr) return 0;
        if (M.find(root) != M.end() and M[root].states[pstate] != -1) return M[root].states[pstate];
        if (pstate == CAMERA) {
            auto d1 = 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
            auto d2 = f(root->left, OK) + f(root->right, OK);
            return M[root].states[pstate] = min(d1, d2);
        }
        if (pstate == USHOULD) return M[root].states[pstate] = 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
        
        // parent is ok
        auto d0 = 1 + f(root->left, CAMERA) + f(root->right, CAMERA);
        int d1 = INT_MAX, d2 = INT_MAX;
        if (root->left) d1 =  f(root->left, USHOULD) + f(root->right, OK);
        if (root->right) d2 = f(root->left, OK) + f(root->right, USHOULD);
        return M[root].states[pstate] = min(d0, min(d1, d2));
    }

    int minCameraCover(TreeNode* root) {
        return f(root, OK);
    }
};

class Solution2 {
private:
    int result;
    int traversal(TreeNode* cur) {

        // 空节点，该节点有覆盖
        if (cur == NULL) return 2;

        int left = traversal(cur->left);    // 左
        int right = traversal(cur->right);  // 右

        // 情况1
        // 左右节点都有覆盖
        if (left == 2 && right == 2) return 0;

        // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if (left == 1 || right == 1) return 2;

        // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        // 情况4
        if (traversal(root) == 0) { // root 无覆盖
            result++;
        }
        return result;
    }
}; 

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minCameraCover( toTree({0,null,0,0,0,null,null,0,0}) ) << endl;
    cout << sol.minCameraCover( toTree({0,0,null,null,0,0,null,null,0,0}) ) << endl;
    cout << sol.minCameraCover( toTree({0,0,0,null,0,0,null,null,0}) ) << endl;
    cout << sol.minCameraCover( toTree({0,}) ) << endl;
    cout << sol.minCameraCover( toTree({0,0,null,0,0}) ) << endl;
    cout << sol.minCameraCover( toTree({0,0,null,0,null,0,null,null,0}) ) << endl;
    return 0;
}
