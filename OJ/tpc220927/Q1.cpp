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

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    vector<LL> v(205);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        fill(ALL(v), 0);
        for (int i = 1; i <= N; i++)
        {
            cin >> v[i];    
            v[i] += v[i-1];
        }
        int Q; cin >> Q;

        LL st = 0;
        while (Q--) {
            LL op, x;
            cin >> op >> x;

            if (op == 1) {
                v[N+1] = x + v[N]; ++N;
            }
            else {
                st += x; st %= v[N];
                auto pos = upper_bound(v.begin(), v.begin() + N + 1, st) - v.begin();
                cout << pos << "\n";
            }
        }
    }
    
    return 0;
}
