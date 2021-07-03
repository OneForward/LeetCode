/*
leet654


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(const vector<int>& A) {
        function<TreeNode*(int, int)> f = [&](int lft, int rht) -> TreeNode* {
            if (lft > rht)  return {};
            auto j = lft;
            for (int i = lft; i <= rht; i++)
                if (A[i] > A[j]) j = i;
            return new TreeNode{ A[j], f(lft, j-1), f(j+1, rht)  };
        };

        return f(0, A.size() - 1);
    }   
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.constructMaximumBinaryTree({3,2,1,6,0,5}) << endl;
    return 0;
}
