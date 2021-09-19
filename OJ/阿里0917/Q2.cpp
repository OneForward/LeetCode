#include <iostream>
#include <cstring>
#include <vector>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

using LL = long long;
const LL MOD = (1LL<<61) - 1;

const int MAXN = 1e5 + 5;
const int MAXK = 100;
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

    LL f[MAXN]{};
    LL g[MAXN]{};
    // f(n, k) 代表以 A[n] 结尾的长度为 k 的 LIS 的数目
    // f(n, k) = sum f(i, k-1) where A[i] < A[n]
    LL ans = N;
    
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < N; i++)
        {
            g[i] = 1; f[i] = 0;
        }
        for (int k = 2; k <= K; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] < A[n]) f[n] += g[i], f[n] %= MOD;
            }
            ans += f[n]; ans %= MOD;
            for (int i = 0; i <= n; i++) g[i] = f[i];
            // memcpy(g, f, sizeof f);
        }
    }

    cout << ans % MOD << endl;
    

    
    return 0;
}
