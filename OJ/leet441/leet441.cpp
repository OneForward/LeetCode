/*
leet441


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int arrangeCoins(long long n) {
        long long lft = 0, rht = n + 1;
        while (lft < rht) {
            long long mid = lft + (rht - lft) / 2;
            if (mid * (mid + 1) / 2 <= n) lft = mid + 1;
            else rht = mid;
        }
        return lft - 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.arrangeCoins(0) << endl;
    cout << sol.arrangeCoins(1) << endl;
    cout << sol.arrangeCoins(5) << endl;
    cout << sol.arrangeCoins(8) << endl;
    cout << sol.arrangeCoins(10) << endl;
    cout << sol.arrangeCoins(1804289383) << endl;
    cout << sol.arrangeCoins(2147483647) << endl;
    return 0;
}
