#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hammingWeight1(size_t n) {
        int cnt = 0;
        while (n) {
            if (n & 1) cnt += 1;
            n >>= 1;
        }
        return cnt;
    }
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt ++;
            n &= (n-1);
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    // printf("%d\n", sol.hammingWeight(10));
    return 0;
}
