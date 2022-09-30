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

const int NMAX = 1e7+5;

// int R[NMAX], S[NMAX];
int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    VI R(NMAX), S(NMAX);
    int T; cin >> T; 
    while (T--) {
        int N; cin >> N;

        // int r, s, r0, s0; cin >> r0;
        int sum_r = 0, sum_s = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> R[i]; sum_r += R[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> S[i]; sum_s += S[i];
        }
        bool ok = true;

        if ( sum_r > sum_s) ok = false;
        for (int i = 0; i < N; i++)
        {
            if (R[i] > S[i] + S[ (i+1) % N] ) ok = false;
        }
        cout << (ok ? "Yes\n" : "No\n") ;
        
    }
    return 0;
}
