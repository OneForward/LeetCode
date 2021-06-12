/*
leet1449


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string largestNumber(const vector<int>& cost, int target) {
        int f[5005]{};
        auto start = *min_element(ALL(cost));
        for (int y = 1; y < start; y++)
        {
            f[y] = -1;
        }
        
        for (int y = start; y <= target; y++)
        {
            int val = -1;
            for (auto&& x: cost) if (y >= x) val = max(val, f[y - x]);
            f[y] = val == -1 ? val : val + 1;
        }
        
        if (f[target] == -1) return "0";


        string s; int len = f[target];

        while (target) {
            for (int i = 9 - 1; i >= 0; i--)
            {
                auto x = target - cost[i];
                if (x >= 0 and f[x] == len-1) {
                    len--; target = x; s += ('0' + i + 1); break;
                }
            }
            
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.largestNumber({4,3,2,5,6,7,2,5,5}, 9) << endl;
    cout << sol.largestNumber({7,6,5,5,5,6,8,7,8}, 12) << endl;
    cout << sol.largestNumber({2,4,6,2,4,6,4,4,4}, 5) << endl;
    cout << sol.largestNumber({6,10,15,40,40,40,40,40,40}, 47) << endl;
    return 0;
}
