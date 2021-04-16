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



// 基于状态转移的动态规划
class Solution {
public:
    struct Tuple
    {
        int a, b, c;
    };
    
    Tuple f(TreeNode* root) { 
        // a: root covered , cover (root, lft, rht) 需要的摄像头数目。
        // b: root whatever, cover (root, lft, rht) 需要的摄像头数目
        // c: root whatever, cover (lft, rht) 需要的摄像头数目
        
        // a = l_c + r_c + 1
        // b = min(a, l_a + r_b, l_b + r_a)
        // c = min(a, l_b + r_b)
        
        if (root == nullptr) return {INT_MAX / 2, 0, 0};
        auto [la, lb, lc] = f(root->left);
        auto [ra, rb, rc] = f(root->right);
        auto a = lc + rc + 1;
        auto b = min(a, min(lb + ra, la + rb));
        auto c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        return f(root).b;
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
