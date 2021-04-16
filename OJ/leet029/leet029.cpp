/*
leet029


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <utility>
#include <bitset>
#include <cassert>
using namespace std;
class Solution {
public:
    int divide(int x, int y) {
        if (y == 1) return x;
        if (y == -1) {
            if (x == INT_MIN) return INT_MAX;
            return -x;
        }
        unsigned lenx = 0, leny = 0; 
        auto get_sign = [] (unsigned& x) { 
            if (x & 0x80000000) { x = ~x + 1; return -1; }
            else return 1;
        };
        auto get_len = [] (unsigned x, unsigned& lenx) {while (x) { lenx++, x >>= 1; }};
        
        unsigned ux = x, uy = y;
        int signx = get_sign(ux), signy = get_sign(uy);
        get_len(ux, lenx); get_len(uy, leny);
        // cout << "ux = " << bitset<32>(ux) << ", lenx = " << lenx << endl;
        // cout << "uy = " << bitset<32>(uy) << ", leny = " << leny << endl;
        int ans = 0; 
        for (int len = lenx - leny; len >= 0 && ux >= 0; --len) {
            if (ux >= (uy<<len)) ans |= (1 << len), ux -= (uy << len );
        }
        // cout << "signx * signy = " << signx * signy << ", ans = " << bitset<32>(ans)  << endl;

        return  signx * signy * ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol; int x = 0x80000000, y = -1;
    printf("ans   = %d\n", sol.divide(x, y));
    // printf("truth = %ull\n", x / y);
    // unsigned x = 14, y = 16;
    // printf("truth = %u\n", x - y);
    // printf("truth = %d\n",  0x80000000);
    // int x = 0;
    // printf("sign of %d = %d\n", x, (x & 0x80000000) ? -1 : 1);
    return 0;
}
