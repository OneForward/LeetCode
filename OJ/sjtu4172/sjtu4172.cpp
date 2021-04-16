/*
    0, 1数组
    操作: 将区间[l, r]全部变为x
    查询: 区间[l, r]中1的数目或者问询最长的连续的1的数目
    [线段树]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e6+11;

struct LCSNode
{
    int begin;
    int val;

    LCSNode(int b=0, int v=0):begin(b), val(v) {}

    LCSNode& operator=(const LCSNode& rhs) {
        if (this == &rhs) return *this;
        begin = rhs.begin; val = rhs.val;
        return *this;
    }

    void set(int b, int v) { begin = b; val = v; }
};

int N, M, op, qlft, qrht, x;
int A[MAX_N];
int SUM[4*MAX_N];
LCSNode LCS[4*MAX_N];
int LAZY[4*MAX_N] = {};

void updateCurNode(int t) {
    int lchild = t<<1, rchild = lchild+1;
    if (LCS[lchild].begin + LCS[lchild].val == LCS[rchild].begin)
        LCS[t].val = LCS[lchild].val + LCS[rchild].val, LCS[t].begin = LCS[lchild].begin;
    else if (LCS[lchild].val < LCS[rchild].val) LCS[t] = LCS[lchild];
    else LCS[t] = LCS[rchild];

    SUM[t] = SUM[lchild] + SUM[rchild];
}

void updateLazyTag(int lft, int rht, int t, int mid) {
    if (LAZY[t]) {
        int lchild = t<<1, rchild = lchild+1;
        LAZY[lchild] = LAZY[rchild] = LAZY[t];
        SUM[lchild] = mid - lft + 1;
        SUM[rchild] = rht - mid;
        LCS[lchild].set(lft,  mid - lft + 1);
        LCS[rchild].set(mid+1, rht - mid);
    }
}

void build(int lft, int rht, int t) {
    if (lft == rht) {
        if (A[lft] == 1) LCS[t].val = SUM[t] = 1, LCS[t].begin = lft;
        else LCS[t].val = SUM[t] = 0, LCS[t].begin = 0;
        return;
    }

    int mid = (lft + rht) >> 1;
    build(lft, mid, t<<1);
    build(mid+1, rht, (t<<1)|1);
    updateCurNode(t);
}



int query_sum(int lft, int rht, int t, int qlft, int qrht) {
    if (qlft <= lft and rht <= qrht) return SUM[t];

    int mid = (lft + rht) >> 1;
    updateLazyTag(lft, rht, t, mid);

    int ret = 0;
    if (qlft <= mid) ret += query_sum(lft, mid, t<<1, qlft, qrht);
    if (qrht >  mid) ret += query_sum(mid+1, rht, (t<<1)|1, qlft, qrht);
    return ret;
}

LCSNode query_lcs(int lft, int rht, int t, int qlft, int qrht) {
    if (qlft <= lft and rht <= qrht) return LCS[t];

    int mid = (lft + rht) >> 1;
    updateLazyTag(lft, rht, t, mid);

    LCSNode rst_lft, rst_rht, rst;
    if (qlft <= mid) rst_lft = query_lcs(lft, mid, t<<1, qlft, qrht);
    if (qrht > mid) rst_rht = query_lcs(mid+1, rht, (t<<1)|1, qlft, qrht);

    if (rst_lft.begin+rst_lft.val == rst_rht.begin)
        rst.val = rst_lft.val + rst_rht.val, rst.begin = rst_lft.begin;
    else if (rst_lft.val < rst_rht.val) rst = rst_lft;
    else rst = rst_rht;
    return rst;
}

void updateInterval(int lft, int rht, int t, int qlft, int qrht, int x) {
    if (qlft <= lft and rht <= qrht) {
        LAZY[t] = x;
        SUM[t] = x * (rht - lft + 1);
        if (x == 0) LCS[t].set(-1, 0);
        else LCS[t].set(lft, rht - lft + 1);
        return;
    }
    int mid = (lft + rht) >> 1;
    updateLazyTag(lft, rht, t, mid);

    if (qlft <= mid) updateInterval(lft, mid, t<<1, qlft, qrht, x);
    if (qrht >  mid) updateInterval(mid+1, rht, (t<<1)|1, qlft, qrht, x);
}



int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu4172/1.in", "r", stdin);
    #endif

    cin >> N >> M;
    for (int i=1; i<=N; ++i) scanf(" %d ", &A[i]);

    build(1, N, 1);

    while (M--) {
        scanf(" %d %d %d ", &op, &qlft, &qrht);
        switch (op) {
            case 1: scanf(" %d ", &x); updateInterval(1, N, 1, qlft, qrht, x); break;
            case 2:
                printf("%d\n", query_sum(1, N, 1, qlft, qrht)); break;
            default:
                printf("%d\n", query_lcs(1, N, 1, qlft, qrht).val);
        }
    }

    return 0;
}
