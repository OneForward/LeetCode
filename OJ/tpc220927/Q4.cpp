/*
tpc220927


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

using LL = long long int;
const int MOD = 998244353;


LL fpower(LL x, int n, LL MOD) {
    if (x == 0 and n) return 0;

    LL ans = 1; x %= MOD;
    while (n) {
        if (n & 1) ans *= x, ans %= MOD; 
        n >>= 1; if (n) x *= x, x %= MOD; 
    }
    return ans;
}

int process_answer(LL a, LL b) {
    auto binv = fpower(b, MOD - 2, MOD);
    return (LL)a * binv % MOD;
}

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int N, K; cin >> N >> K;
    
    VVI tree(N+1);

    int x, y;
    VI degree(N+1);
    for (int i = 1; i < N; i++)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        degree[x]++;
        degree[y]++;
    }
    
    LL sum_leaf_nodes = 0;
    LL L = 0;
    for (auto&& deg: degree) {
        if (deg == 1)  L++;
    }

    sum_leaf_nodes = L * (N - 1);
    for (int x = 0; x <= N; x++)
    {
        for (auto&& y: tree[x]) {
            if (degree[x] == 1 or degree[y] == 1) {
                sum_leaf_nodes--;
                if (degree[x] == 2 or degree[y] == 2) sum_leaf_nodes++;
            }
        }
    }

    // sum_leaf_nodes = L * (N - 1) + (N - L) * L;
    cout << process_answer(sum_leaf_nodes, N - 1) << "\n";
    // cout << process_answer(5, 2) << "\n";

    
    return 0;
}
