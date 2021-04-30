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
    // BFS 使用 队列， O(N)

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> Q; Q.push(root); 
        while (Q.size()) {
            auto len = Q.size();
            while (len--) {
                auto p = Q.front(); Q.pop();
                if (p == nullptr) s += "null,";
                else {
                    s += to_string(p->val) + ",";
                    Q.push(p->left);
                    Q.push(p->right);
                } 
            }
        }
        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& s) {
        if (s == "null,") return {};

        vector<string> v;
        auto lft = 0;
        while (lft < s.size() ) {
            auto rht = s.find(',', lft);
            auto val = s.substr(lft, rht-lft);
            v.push_back(val);
            lft = rht + 1;
        }
        
        auto root = new TreeNode{stoi(v[0])};
        auto p = 1;
        queue<TreeNode*> Q; Q.push(root);

        while (p < v.size()) {
            auto node = Q.front(); Q.pop();
            auto lval = v[p];
            auto rval = v[p+1];
            if (lval != "null") {
                node->left = new TreeNode{stoi(lval)};
                Q.push(node->left);
            }
            if (rval != "null") {
                node->right = new TreeNode{stoi(rval)};
                Q.push(node->right);
            }
            p += 2;
        }
        return root;
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
