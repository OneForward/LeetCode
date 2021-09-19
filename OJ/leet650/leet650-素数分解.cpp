/*
leet650


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int minSteps(int N) {
        // O(N^0.5)
        int ans = 0;
        for (int d = 2; N > 1; d++)
        {
            while (N % d == 0) N /= d, ans += d;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minSteps(10) << endl;
    cout << sol.minSteps(5) << endl;
    cout << sol.minSteps(3) << endl;
    cout << sol.minSteps(2) << endl;
    cout << sol.minSteps(1) << endl;
    return 0;
}
