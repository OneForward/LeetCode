#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<long long>;



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

    sort(ALL(A), greater<long long>{});
    
    long long f = 0, sum = 0;
    int i = 0;
    for (; i < N; i++)
    {
        auto x = A[i];
        f += sum;
        sum += x;
        if (sum < 0) break;
    }
    
    for (; i < N-K-1; i++)
    {
        auto x = A[i];
        f += sum;
        sum += x;
    }
    
    cout << f;
    return 0;
}
