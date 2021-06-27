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
    long long g[26]{};
    const int MOD = 20210101;
    for (auto&& ch: s) {
        int gi = 1;
        for (int i = 0; i < 26; ++i) {
            if (i != ch - 'a') gi += g[i], gi %= MOD;
        }
        g[ch - 'a'] += gi; g[ch - 'a'] %= MOD;
    }
    for (auto&& gi: g) ans += gi, ans %= MOD;
    cout << ans;
    return 0;
}
