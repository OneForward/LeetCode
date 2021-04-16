/*
leet190


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits1(uint32_t n) {
        if (n == 0) return 0;
        int ans = 0, prev = 0, topbit = 1<<31;
        while ((n & topbit) == 0) topbit >>= 1, prev++;
        while (n) {
            ans <<= 1; ans |= (n & 1); n >>= 1; 
        }
        return ans << prev;
    }
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   int x;
    
    x = 15; cout << bitset<32>(x) << endl << bitset<32>(sol.reverseBits(x)) << endl << endl;
    x = 43261596; cout << bitset<32>(x) << endl << bitset<32>(sol.reverseBits(x)) << endl << endl;
    x = 4294967293; cout << bitset<32>(x) << endl << bitset<32>(sol.reverseBits(x)) << endl << endl;
    return 0;
}
