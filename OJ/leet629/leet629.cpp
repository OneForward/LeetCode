#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

const int MOD = 1000000000+7;

class Solution {
public:
    long A[1001][1001] = {};
    
    int kInversePairs(int N, int K) {
        A[1][0] = 1;
        for (int n=1; n<N; ++n) {
            A[n+1][0] = 1;
            for (int k=1; k<=K; ++k) {
                A[n+1][k] = (A[n][k] + A[n+1][k-1]) % MOD;
                if (k > n)  A[n+1][k] += (MOD - A[n][k-n-1]), A[n+1][k] %= MOD;
            }
        }
        return A[N][K] % MOD;
    }
};


int main()
{
    Solution sol;
    sol.kInversePairs(10, 10);
}