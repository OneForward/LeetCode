/*
lcof15


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.hammingWeight(0) << endl;
    cout << sol.hammingWeight(0b00000000000000000000000000001011) << endl;
    cout << sol.hammingWeight(0b00000000000000000000000010000000) << endl;
    cout << sol.hammingWeight(0b11111111111111111111111111111101) << endl;
    return 0;
}
