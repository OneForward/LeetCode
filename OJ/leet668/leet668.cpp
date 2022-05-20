/*
leet668


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(), A.end()
using VI = vector<int>;
using VVI = vector<VI>;

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        if (m > n) return findKthNumber(n, m, k);

        auto countLessEq = [&](int x) -> int
        {
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                cnt += min(x / i, n);
            return cnt;
        };

        int lft = 1, rht = m * n + 1;
        while (lft < rht)
        {
            auto mid = lft + (rht - lft) / 2;
            if (countLessEq(mid) < k)
                lft = mid + 1;
            else
                rht = mid;
        }
        return lft ;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.findKthNumber(3, 3, 5) << endl;
    cout << sol.findKthNumber(2, 3, 6) << endl;
    cout << sol.findKthNumber(45, 12, 471) << endl;
    return 0;
}
