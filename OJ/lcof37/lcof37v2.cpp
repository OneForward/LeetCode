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
    TreeNode* r;
    string serialize(TreeNode* root) {
        r = root; return {};
    }

    TreeNode* deserialize(string data) {
        return r;
    }
};


int main(int argc, char const *argv[])
{
    Codec codec;
    cout << codec.serialize( toTree({1,null, 2,3,4}) ) << endl;
    cout << codec.deserialize( codec.serialize( toTree({1,null, 2,3,4}) ) ) << endl;
    
    return 0;
}
