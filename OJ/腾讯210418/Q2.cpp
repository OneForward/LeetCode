#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;


long long f[2005][2005];

int main()
{
    // freopen("in.txt", "r", stdin);

    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();

    vector<int> v;

    auto cmp = [&](int i, int j) {
        return S[i] < T[j];
    };

    for (int i = N - 1; i >= 0; i--)
    {
        while (v.size() and S[v.back()] >= S[i]) v.pop_back();
        v.push_back(i);
        
        f[i][M] = 1;
        for (int j = M - 1; j >= 0; j--)
        {
            auto pos = lower_bound(v.begin(), v.end(), j, cmp);
            if (pos == v.begin()) f[i][j] = max(f[i][j+1], (long long)M - j) ;
            else {
                pos--;
                f[i][j] = max(f[i][j+1], (long long)N - *pos + M - j);
            }
        }
        
    }


    int Q, qi, qj; cin >> Q;
    while (Q--) {
        cin >> qi >> qj;
        cout << f[qi-1][qj-1] << "\n";
    }

    return 0;
}
