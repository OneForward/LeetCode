/*
leet449


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return ",";
        return to_string(root->val) + ","
            + serialize(root->left)
            + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* _deserialize( string_view& s) {
        if (s.empty()) return {};

        auto pos = s.find(',');
        auto sub = s.substr(0, pos);
        s = s.substr(pos + 1);
        if (sub.empty()) return {};

        auto root = new TreeNode{ stoi( string { sub } )};
        root->left = _deserialize(s);
        root->right = _deserialize(s);
        return root;
    }

    TreeNode* deserialize(string data) {
        auto s = string_view{ data };
        return _deserialize( s );
    }
};

// Your Codec object will be instantiated and called as such:



int main(int argc, char const *argv[])
{
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    cout << deser->deserialize( ser->serialize( toTree({2, 1, 3}) ) ) << endl;
    cout << deser->deserialize( ser->serialize( toTree({ }) ) ) << endl;
    return 0;
}
