/*
leet483


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string smallestGoodBase(string n) {
        
        using LL = long long;
        auto x = stoll(n);
        auto dividable = [](LL x, LL y) { return x % y == 0; };
        auto ispower = [&](LL x, LL B) {
            while (x > 1) {
                if (not dividable(x, B)) break;
                x /= B;
            }
            return x == 1;
        };
        
        // >= 3 ?
        for (LL B = 2; B < 1000'000; B++)
        {
            if (not dividable(x - 1, B)) continue;
            if (ispower(x - (x - 1) / B, B)) return to_string(B);
        }

        // = 2 ?
        LL B = sqrt(x - 1);
        if (B * B + B + 1 == x) return to_string(B);

        return to_string(x - 1);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.smallestGoodBase("13") << endl;
    // cout << sol.smallestGoodBase("4681") << endl;
    // cout << sol.smallestGoodBase("1000000000000000000") << endl;
    cout << sol.smallestGoodBase("2251799813685247") << endl;
    return 0;
}
