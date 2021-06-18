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

        auto f = [](LL B, LL K) {
            if (B == 0) return 0LL;

            LL sum = 1, x = 1;
            while (K--)
            {
                if (x >= LLONG_MAX / B) return LLONG_MAX; 
                x *= B;
                if (sum >= LLONG_MAX - x) return LLONG_MAX; 
                sum += x; 
            }
            return sum;
        };
        
        auto solve = [&](LL K, LL x) -> pair<bool, LL> {
            LL lft = 2, rht = sqrt(x) + 1;
            while (lft < rht) {
                auto mid = lft + (rht - lft) / 2;
                if (f(mid, K) >= x) rht = mid;
                else lft = mid + 1;
            }
            return pair{f(lft, K) == x, lft};
        };

        for (int K = 63; K >= 2; K--)
        {
            auto [ok, B] = solve(K, x);
            if (ok) return to_string(B);
        }
        
        return to_string(x - 1);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.smallestGoodBase("13") << endl;
    cout << sol.smallestGoodBase("4681") << endl;
    cout << sol.smallestGoodBase("1000000000000000000") << endl;
    cout << sol.smallestGoodBase("2251799813685247") << endl;
    cout << sol.smallestGoodBase("470988884881403701") << endl;
    return 0;
}
