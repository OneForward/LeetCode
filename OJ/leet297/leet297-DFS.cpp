/*
leet297


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



class Codec {
public: 
    // DFS 递归法， O(N), 52ms

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) { return "null,";}
        string s = to_string(root->val) + ',';
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* _deserialize(string_view& s) {
        auto pos = s.find(',');
        auto val = s.substr(0, pos);
        s = s.substr(pos+1); // 消耗 s 的第一个结点
        if (val == "null") return {};

        auto root = new TreeNode{stoi(string(val))};
        
        root->left = _deserialize(s);
        root->right = _deserialize(s);
        return root;
    }
    TreeNode* deserialize(const string& s) {
        string_view sview = s;
        return _deserialize(sview);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main(int argc, char const *argv[])
{
    Codec ser, deser;
    // cout << toTree( {1,2,3,null,null,4,5} ) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,2,3,null,null,4,5,6,7} ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,12,3,null,null,4,5} ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( { } ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1, } ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,12, } ) )) << endl;
    return 0;
}
