#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;




int main()
{
    // freopen("in.txt", "r", stdin);

    const int MOD = 1e9 + 7;
    int N;
    cin >> N;

    VI A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int sum = accumulate(ALL(A), 0);
    if (sum % 2) { cout << "No solution!"; return 0; }

    int target = sum / 2;
    
    VI f(target + 1); f[0] = 1;
    for (auto&& x: A) {
        for (int t = target; t >= x; t--)
        {
            f[t] += f[t-x]; f[t] %= MOD;
        }
    }
    cout << f[target] ;
    return 0;
}
