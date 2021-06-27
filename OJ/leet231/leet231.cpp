/*
leet231


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        cout << (n & (-n)) << endl;
        cout << (n & (n-1)) << endl;
        return  n and (n & (n-1)) == 0;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;
    Solution sol;   
    cout << sol.isPowerOfTwo(0) << endl;
    cout << sol.isPowerOfTwo(16) << endl;
    return 0;
}
