/*
线段树, Lazy Tag, 区间增删, 区间索引
*/
#include <iostream>
#include <fstream>
using namespace std;

#define lchild L,mid,2*t
#define rchild mid+1,R,2*t+1

const int MAX_N = 107;
long long SUM[MAX_N<<2], LAZY_TAG[MAX_N<<2], A[MAX_N];

void updateCurNode(int t) {
    SUM[t] = SUM[2*t] + SUM[2*t+1];
}

void pushDownLazyTag(int t, int lenL, int lenR) {
    if (LAZY_TAG[t]) {
        LAZY_TAG[t*2] += LAZY_TAG[t];
        LAZY_TAG[t*2+1] += LAZY_TAG[t];
        SUM[t*2] += LAZY_TAG[t] * lenL;
        SUM[t*2+1] = LAZY_TAG[t] * lenR;
        LAZY_TAG[t] = 0;
    }
}
//static int times = 0;
void build(int L, int R, int t) {
    // printf("build %d recursions\n", ++times);
    LAZY_TAG[t] = 0;
    if (L == R) { SUM[t] = A[L]; return;}
    int mid = (L + R) / 2;
    build(lchild);
    build(rchild);
    updateCurNode(t);
}

// A[k] += c
void update(int L, int R, int t, int k, int c) {
    if (L <= k and k <= R) { SUM[t] += c; return;}
    int mid = (L + R) / 2;
    if (k <= mid) update(lchild, k, c);
    else update(rchild, k, c);
}
// A[a..b] += c
void update(int L, int R, int t, int a, int b, int c) {
    if (a <= L and R <= b) { SUM[t] += c * (R - L + 1); LAZY_TAG[t] += c; return; }
    int mid = (L + R) / 2;
    if (a <= mid) update(lchild, a, b, c);
    if (mid < b ) update(rchild, a, b, c);
    updateCurNode(t);
}


long long query(int L, int R, int t, int a, int b) {
    if (a <= L and R <= b) return SUM[t]; // final recursion

    int ans = 0, mid = (L + R) / 2;
    // printf("query %d times\n", ++times);
    pushDownLazyTag(t, mid-L+1, R-mid);
    if (a <= mid) ans += query(lchild, a, b);
    if (mid < b) ans += query(rchild, a, b);
    return ans;
}

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N >> Q;
    for (int i=1; i<=N; ++i) cin >> A[i];
    build(1, N, 1);
    char ch; int a, b, c;
    while (Q--) {
        cin >> ch >> a >> b;
        if (ch == 'C') {
            cin >> c;
            update(1, N, 1, a, b, c);
        }
        else {
            cout << query(1, N, 1, a, b) << endl;
        }
    }
    return 0;
}
