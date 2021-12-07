/*
leet029


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int div(int a, int b) {
        // a, b < 0
        if (a > b) return 0;
        int res = 1, step = b;
        while (a - step <= step) {
            step += step;
            res += res;
        }
        return res + div(a - step, b);
    }

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN and divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        int flag = 0;
        if (dividend > 0) dividend = -dividend, flag ^= 1;
        if (divisor > 0) divisor = -divisor, flag ^= 1;
        return flag ? -div(dividend, divisor) : div(dividend, divisor);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.divide(10, 3) << endl;
    cout << sol.divide(7, -3) << endl;
    return 0;
}
