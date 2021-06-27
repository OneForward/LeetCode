/*
leet1498


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

const long long MOD = 1e9 + 7;
long long fastPow(long long x, int n) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % MOD;
        x *= x; n >>= 1;
        x %= MOD; 
    }
    return ans;
}

class Solution {
public:
    int numSubseq( vector<int> A, const int target) {
        sort(A.begin(), A.end());
        long long ans = 0;
        for (auto &&x : A) if (x <= target / 2) ans++;
        
        int lft = 0, rht = A.size() - 1;
        while (lft < rht) {
            while (lft < rht and A[lft] + A[rht] > target) rht--;
            ans += fastPow(2, rht - lft) - 1; ans %= MOD;
            lft++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numSubseq({14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14}, 22) << endl;
    cout << sol.numSubseq({3,5,6,7}, 9) << endl;
    cout << sol.numSubseq({3,3,6,8}, 10) << endl;
    cout << sol.numSubseq({2,3,3,4,6,7}, 12) << endl;
    return 0;
}
