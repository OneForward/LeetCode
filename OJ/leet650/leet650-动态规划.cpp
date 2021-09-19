/*
leet650


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int minSteps(int N) {
        int f[1001]{};
        for (int n = 2; n <= N; n++)
        {
            f[n] = INT_MAX;
            for (int i = 1; i <= n; i++)
            {
                if (n % i == 0) f[n] = min(f[n], f[i] + n / i);
            }
        }
        return f[N];
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
