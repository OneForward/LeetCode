/*
leet268


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> A) {
        int n = A.size();
        int An = 1;
        for (auto&& x0: A) {
            auto x = abs(x0);
            if (x == n) An = -An;
            else A[x] = -A[x];
        }
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) return i;
            if (A[i] == 0) zero = i;
        }
        if (An > 0) return n;
        return zero;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.missingNumber({3,0,1}) << endl;
    cout << sol.missingNumber({0,1}) << endl;
    cout << sol.missingNumber({1,3,0}) << endl;
    cout << sol.missingNumber({9,6,4,2,3,5,7,0,1}) << endl;
    cout << sol.missingNumber({0}) << endl;
    return 0;
}
