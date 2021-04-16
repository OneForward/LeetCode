/*
lcof26


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
    bool isSame(TreeNode* A, TreeNode* B ) {
        if (not B) return true;
        if (not A or (A->val != B->val) ) return false;
        return isSame(A->left, B->left) and isSame(A->right, B->right) ;
        
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr) return false;
        if (isSame(A, B)) return true;
        return isSubStructure(A->left, B) or isSubStructure(A->right, B); 
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isSubStructure( toTree( {10,12,6,8,3,11} ), toTree({10,12,6,8}) ) << endl;
    cout << sol.isSubStructure( toTree( {1,2,3,4} ), toTree({3}) ) << endl;
    return 0;
}
