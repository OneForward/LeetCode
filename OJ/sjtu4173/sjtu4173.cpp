/*
    二分搜索，滑动窗口 O(N log L)
*/


#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 4e6 + 5;
char s[MAX];
int N, x, y, x0, y0, dx, dy;
int Counter[4], C[4];


int M(char ch) {
    switch (ch)
    {
    case 'L': return 0;
    case 'R': return 1;
    case 'D': return 2;
    default : return 3;
    }
}

bool local_ok() {
    auto [L, R, D, U] = C;
    return min(L, R + dx) + min(D, U + dy) >= (dx + dy) / 2;
};

bool ok(int len) {
    memset(C, 0, sizeof C);

    for (int i = 0; i < len; i++) {
        C[M(s[i])] ++;
        if (local_ok()) return true;
    }

    for (int i = len; i < N; i++)
    {
        C[M(s[i-len])]--;
        C[M(s[i])]++;
        if (local_ok()) return true;
    }

    return false;
};

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N >> s >> x >> y;

    auto steps = abs(x) + abs(y);

    if (steps > N or ((steps - N) & 1) ) { // 距离至多为 N 且距离的奇偶性不变
        cout << -1; return 0;
    }

    
    for (int i = 0; i < N; i++)
        Counter[M(s[i])]++;
    
    x0 = Counter[1] - Counter[0];
    y0 = Counter[3] - Counter[2];
    dx = x - x0, dy = y - y0;

    auto lft = 0, rht = steps + 1;
    while (lft < rht) {
        auto mid = (lft + rht) / 2;
        if (ok(mid)) rht = mid;
        else lft = mid + 1;
    }
    cout << lft;
    
    return 0;
}