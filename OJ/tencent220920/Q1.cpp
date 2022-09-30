/*
tencent220920


*/

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

struct Pair
{
    int p, q, i;
};
bool operator<(const Pair& lft, const Pair& rht)  {
    return lft.p < rht.p or (lft.p == rht.p and lft.q < rht.q);
}
bool operator>=(const Pair& lft, const Pair& rht)  {
    return !(lft < rht);
}

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    int T = N * (N - 1) / 2;

    int x, y, a, b;

    vector<Pair> f(N);
    for (int i = 0; i < N; i++)
    {
        f[i].i = i;
    }
    

    while (T--) {
        cin >> x >> y >> a >> b;
        f[x-1].q += a;
        f[y-1].q += b;
        if (a == 2) f[x-1].p++;
        if (b == 2) f[y-1].p++;
    }
    auto f0 = f;
    sort(ALL(f));

    auto key = f[N - M];
    for (int i = 0; i < N; i++)
    {
        if ( f0[i] >= key ) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}
;