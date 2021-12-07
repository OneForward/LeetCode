/*
leet319


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int bulbSwitch(int n) {
        // count prime square in [0, n]
        const long long M = 1e5;
        bool iscomposite[M]{true}; // 1 is considered as prime
        for (int p = 2; p <= n and p < M; p++)
        {
            if (iscomposite[p]) continue;
            for (int x = 2 * p; x <= n and x < M; x += p)
            {
                iscomposite[x] = true;
            }
        }
        int ans = 0;
        for (int x = 1; x <= n / x; x++)
        {
            if (iscomposite[x]) continue;
            ans++;
        }
        

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.bulbSwitch(0) << endl;
    cout << sol.bulbSwitch(1) << endl;
    cout << sol.bulbSwitch(3) << endl;
    cout << sol.bulbSwitch(4) << endl;
    cout << sol.bulbSwitch(16) << endl;
    cout << sol.bulbSwitch(10) << endl;
    cout << sol.bulbSwitch(1e9) << endl;
    return 0;
}
