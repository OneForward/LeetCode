#include <iostream>
#include <cstring>
#include <vector>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;
#define ALL(A) A.begin(),A.end()
using LL = long long;
using VI=vector<LL>;
using VVI=vector<VI>;

const LL MOD = (1LL<<61) - 1;

const int MAXN = 1e5 + 5;
const int MAXK = 72;
int main()
{
    freopen("in.txt", "r", stdin);

    int N, K;
    cin >> N >> K;
    
    VI A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    // cout << A << endl;

    VVI f(MAXN, VI(MAXK));
    // f(n, k) 代表以 A[n] 结尾的长度为 k 的 LIS 的数目
    // f(n, k) = sum f(i, k-1) where A[i] < A[n]
    LL ans = N;
    for (int n = 0; n < N; n++)
    {
        f[n][1] = 1;
        for (int k = 2; k <= K; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] < A[n]) f[n][k] += f[i][k-1], f[n][k] %= MOD;
            }
            ans += f[n][k]; ans %= MOD;
        }
    }

    cout << ans << endl;
    

    
    return 0;
}
