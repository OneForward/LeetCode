/*
    区间最大问题
    Sliding Window with velocity = 1, print the maximal in the window range
    [线段树]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

#define lson lft, mid, t<<1
#define rson mid+1, rht, t<<1|1

const int MAX_N = 2e6+11;

int K, N;
int A[MAX_N];
int MAX[4*MAX_N];

inline int max(int a, int b) { return a > b ? a : b; }

void updateCurNode(int t) {
    MAX[t] = max(MAX[2*t], MAX[2*t+1]);
}

void build(int lft, int rht, int t) {
    if (lft == rht) { MAX[t] = A[lft]; return; }

    int mid = (lft + rht) >> 1;
    build(lson);
    build(rson);
    updateCurNode(t);
}

int query(int lft, int rht, int t, int qlft, int qrht) {
    if (qlft <= lft and rht <= qrht) return MAX[t];

    int mid = (lft + rht) >> 1, rst = 0xFFFFFFFF;
    if (qlft <= mid) rst = max( rst, query(lson, qlft, qrht) );
    if (mid  < qrht) rst = max( rst, query(rson, qlft, qrht) );
    return rst;
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1541/1.in", "r", stdin);
    #endif

    cin >> K >> N;
    for (int i=1; i<=N; ++i) scanf(" %d ", &A[i]);
    build(1, N, 1);

    for (int i=1; i<=N+1-K; ++i) printf("%d ", query(1, N, 1, i, i+K-1));
    return 0;
}
