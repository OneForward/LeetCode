/*
    字符串哈希
    给定字符串S1...SN, 随机问询如下三个问题
    1 x : Sx 是否在 S1...Sx-1中出现, O(1)
    2 x y: 询问 Sx, Sy 的最长公共前缀长度, O(log L)
    3 x y: 询问 Sx, Sy 的最长公共后缀长度, O(log L)
*/

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int MAX = 1000005;
using ULL = unsigned long long;
ULL pos[MAX],  prefix[MAX], suffix[MAX];
bool same[MAX];
char buffer[MAX];
int N, M, x, y, op;
unordered_set<int> S;

int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> buffer;
        int n = strlen(buffer);
        pos[i] = n + pos[i-1];
        prefix[pos[i - 1]] = buffer[0];
        suffix[pos[i - 1]] = buffer[n-1];
        for (int j = 1; j < n; j++)
        {
            prefix[ pos[i - 1] + j ] = prefix[ pos[i - 1] + j - 1 ]  * 1313 + buffer[j];
            suffix[ pos[i - 1] + j ] = suffix[ pos[i - 1] + j - 1 ]  * 1313 + buffer[n - 1 - j];
        }
        if (S.find(prefix[pos[i] - 1]) != S.end()) same[i] = true;
        else S.insert(prefix[pos[i] - 1]);
    }

    auto lcp = [&](ULL* prefix, const int x, const int y) {
        int m = pos[x] - pos[x-1], n = pos[y] - pos[y-1];
        int lft = 0, rht = min(m, n), px = pos[x-1], py = pos[y-1];
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (prefix[px + mid] != prefix[py + mid])  rht = mid;
            else lft = mid + 1;
        }
        return lft;
    };
    

    cin >> M;
    while (M--) {
        cin >> op;
        switch(op) {
            case 1: cin >> x; cout << ( same[x] ? "yes\n" : "no\n" ); break;
            case 2: cin >> x >> y; cout <<  lcp(prefix, x, y) << "\n"; break;
            default: cin >> x >> y; cout <<  lcp(suffix, x, y) << "\n";
        }
    }
    return 0;
}