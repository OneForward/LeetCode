/*
lcof44


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int findNthDigit(const int N) {
        int n = 9, f = 987654321, ten = 100000000; // f = ...4321
        while (f > (N - 1) / 9) {
            f -= n * ten; n--; ten /= 10;
        }
        n++; ten *= 10;
        auto delta = n == 1 ? N : N - f * 9 - 1;
        auto x = ten + delta / n; auto pos = n - delta % n - 1;
        while (pos--) x /= 10;
        return x % 10;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    for (int i = 0; i < 20; i++)
    {
        printf("f(%d) = %d\n", i, sol.findNthDigit(i));
    }
    
    // cout << sol.findNthDigit(3) << endl;
    // cout << sol.findNthDigit(10) << endl;
    // cout << sol.findNthDigit(11) << endl;
    // cout << sol.findNthDigit(12) << endl;
    // cout << sol.findNthDigit(13) << endl;
    // cout << sol.findNthDigit(14) << endl;
    return 0;
}
