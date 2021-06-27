/*
lcof12


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int sumNums(int n) {
        return sizeof(bool[n][n+1]) >> 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.sumNums(100) << endl;
    return 0;
}
