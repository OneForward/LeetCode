/*
    [排序][贪心]
*/


#include <iostream>
#include <algorithm>

using namespace std;


#define FOR(i,a,b) for(int i=(a);i<(b);++i)


const int MAX = 1e5 + 5;
int N;
struct Mountain
{
    long long x, y;
};

Mountain M[MAX];
int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> M[i].x;
    for (int i = 0; i < N; i++) cin >> M[i].y;

    auto cmp = [&](const Mountain& lft, const Mountain& rht) { 
        return lft.x < rht.x;
    };
    sort(M, M+N, cmp);

    int ans = (N > 1) ? 2 : 1;

    FOR(i, 1, N-1) {
        if (M[i].x - M[i].y > M[i-1].x) ans++;
        else if (M[i].x + M[i].y < M[i+1].x) {
            ans++; M[i].x += M[i].y;
        }
    }
    
    cout << ans;

    return 0;
}
