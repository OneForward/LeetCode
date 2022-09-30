/*
tpc220927


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    VI v(1e9+105);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        v[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            cin >> v[i];    
            v[i] += v[i-1];
        }
        int Q; cin >> Q;

        int st = 0;
        while (Q--) {
            int op, x;
            cin >> op >> x;

            if (op == 1) {
                v[N+1] = x + v[N]; ++N;
            }
            else {
                st += x; st %= v[N];
                auto pos = lower_bound(v.begin(), v.begin() + N, st) - v.begin();
                cout << pos << "\n";
            }
        }
    }
    
    return 0;
}
