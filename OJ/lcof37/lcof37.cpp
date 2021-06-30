/*
lcof37


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Codec {
public:

    string serialize(TreeNode* root) {
        if (not root) return "null,";
        return to_string(root->val) + "," + 
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        function<TreeNode*(string_view&)> f = [&](string_view& s) -> TreeNode* {
            if (s.empty()) return {};

            auto pos = s.find(',');
            auto val = s.substr(0, pos);
            s = s.substr(pos + 1);
            if (val == "null") return {};

            auto root = new TreeNode{stoi(string{val})};
            root->left  = f(s); 
            root->right = f(s);
            return root;
        };
        auto s = string_view{data};
        return f(s);
    }
};


int main(int argc, char const *argv[])
{
    Codec codec;
    cout << codec.serialize( toTree({1,null, 2,3,4}) ) << endl;
    cout << codec.deserialize( codec.serialize( toTree({1,null, 2,3,4}) ) ) << endl;
    
    return 0;
}
