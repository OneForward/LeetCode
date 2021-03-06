/*
leet342


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        cout << (n & (-n)) << endl;
        if (not (n >= 1 and (n & (-n)) == n)) return false;
        auto cnt = 0;
        while (n) {
            cnt++; n >>= 1;
        }
        return cnt % 2 == 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isPowerOfFour(1) << endl;
    cout << sol.isPowerOfFour(4) << endl;
    cout << sol.isPowerOfFour(16) << endl;
    return 0;
}
