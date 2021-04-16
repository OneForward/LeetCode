/*
luogu1714


*/


#include <iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);

    int N, M; cin >> N >> M;
    int* A = new int[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    auto f = 0, cnt = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (f > 0) f += A[i], cnt++;
        else f = A[i], cnt = 1;
        if (cnt > M) {
            f -= A[i-M]; cnt--;
            auto y = f;
            for (int j = i-M+1; j < i; j++)
            {
                y -= A[j];
                if (y >= f) f = y, cnt = i - j;
            }
        }
        ans = max(ans, f);
    }
    cout << ans;
    
    
    return 0;
}
