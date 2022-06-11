/*
leet829


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int consecutiveNumbersSum(int f) {
        // a = f / n - (n - 1) / 2
        int ans = 1;
        for (int n = 2; n <= (int)sqrt(2 * f) + 1; n++)
        {
            auto a = 2 * f - n * (n - 1);
            if (a <= 0 or a % (2 * n)) continue;
            ans++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.consecutiveNumbersSum(5) << endl;
    cout << sol.consecutiveNumbersSum(9) << endl;
    cout << sol.consecutiveNumbersSum(15) << endl;
    return 0;
}
