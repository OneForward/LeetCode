/*
leet498


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    VI findDiagonalOrder(const VVI& mat) {
        int R = mat.size(), C = mat[0].size();
        VI v; v.reserve(R * C);
        for (int f = 0; f < R + C - 1; f++) {
            if (f % 2 == 0) {
                for (int c = max(0, f - R + 1); c <= min(f, C-1); c++)
                    v.push_back(mat[f-c][c]);
            }
            else {
                for (int c = min(f, C-1); c >= max(0, f - R + 1); c--)
                    v.push_back(mat[f-c][c]);
            }
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findDiagonalOrder({{1,2,3},{4,5,6},{7,8,9}}) << endl;
    cout << sol.findDiagonalOrder({{1,2},{3,4},}) << endl;
    return 0;
}
