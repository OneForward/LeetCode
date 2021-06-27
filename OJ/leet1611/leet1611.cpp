/*
leet1611


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int g) {
        // 逆格雷码, O(log N)
        int x = 0;
        while (g) x ^= g, g >>= 1;
        return x;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minimumOneBitOperations(0) << endl;
    cout << sol.minimumOneBitOperations(3) << endl;
    cout << sol.minimumOneBitOperations(9) << endl;
    cout << sol.minimumOneBitOperations(333) << endl;
    return 0;
}
