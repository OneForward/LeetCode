/*
leet875


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        // min_x f(x) <= h
        auto f = [&](int k) {
            int cnt = 0;
            for (auto&& p: piles) {
                cnt += (p + k - 1 ) / k;
            }
            return cnt;
        };

        int lft = 1, rht = 2e9;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (f(mid) <= h) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minEatingSpeed({3,6,7,11}, 8) << endl;
    cout << sol.minEatingSpeed({30,11,23,4,20}, 5) << endl;
    cout << sol.minEatingSpeed({30,11,23,4,20}, 6) << endl;
    return 0;
}
