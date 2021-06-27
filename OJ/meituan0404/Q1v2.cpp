/*
meituan0404


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;




int main(int argc, char const *argv[])
{
    freopen("Q1in.txt", "r", stdin);

    string s; cin >> s;

    long long ans = 1;
    long long g[26][26]{};
    long long f[26]{};
    const int MOD = 20210101;
    for (auto&& ch: s) {
        auto a = ch - 'a';
        for (int b = 0; b < 26; ++b) {
            if (b == a) continue;
            int gi = 1;
            for (int x = 0; x < 26; ++x) {
                if (x == b ) continue;
                gi += g[x][b], gi %= MOD;
            }
            g[a][b] = gi; // ends_with a, no b
        }
        f[a] += 1;
        for (int x = 0; x < 26; x++)
        {
            if (x == a) continue;
            f[a] += g[x][a]; // ends_with x, no a
            f[a] %= MOD;
        }
    }
    for (auto&& fi: f) 
        ans += fi, ans %= MOD;
    cout << ans;
    return 0;
}
