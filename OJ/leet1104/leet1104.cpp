/*
leet1104


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    vector<int> pathInZigZagTree(int x) {
        int R = 1, C, len = 0;
        while (R <= x) R <<= 1, len++;
        R >>= 1; len--;
        C = len & 1 ? x - R : R * 2 - x - 1;
        vector<int> v;
        while (R) {
            v.push_back(len & 1 ? R + C : R * 2 - C - 1);
            R >>= 1; C >>= 1; len--;
        }
        return vector(v.rbegin(), v.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.pathInZigZagTree(14) << endl;
    cout << sol.pathInZigZagTree(26) << endl;
    return 0;
}
