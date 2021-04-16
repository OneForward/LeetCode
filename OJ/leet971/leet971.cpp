/*
leet971


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
    vector<int> flipMatchVoyage(TreeNode* root, const vector<int>& voyage) {
        int i = 0; v.clear();
        auto ok = flipMatchVoyage(root, voyage, i);
        if (ok) return v;
        return {-1};
    }

    vector<int> v;
    bool flipMatchVoyage(TreeNode* root, const vector<int>& voyage, int& i) {
        if (root->val != voyage[i]) return false;
        
        i++; auto ok = true;
        if (root->left and root->left->val != voyage[i]) {
            v.push_back(root->val);
            if (root->right) ok = ok and flipMatchVoyage(root->right, voyage, i);
            if (root->left) ok = ok and flipMatchVoyage(root->left, voyage, i); 
            return ok;
        }
        if (root->left) ok = ok and flipMatchVoyage(root->left, voyage, i); 
        if (root->right) ok = ok and flipMatchVoyage(root->right, voyage, i);
        return ok;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.flipMatchVoyage( toTree({1,}) , { 1} ) << endl;
    cout << sol.flipMatchVoyage( toTree({1,2}) , {2, 1} ) << endl;
    cout << sol.flipMatchVoyage( toTree({1,2,3}) , {1,3,2} ) << endl;
    cout << sol.flipMatchVoyage( toTree({1,2, 3}) , {1,2,3} ) << endl;
    return 0;
}
