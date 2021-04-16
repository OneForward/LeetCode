/*
   问询区间[1..2k+1]的第k大值(即中位数)
   划分树, 快排
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e5+5;
const int DEEP = 19;

struct PatitionTreeLevel
{
    int* num;
    int* cnt;
};

PatitionTreeLevel tree[DEEP];
int* sorted;

int N;

void init() {
    for (int i=0; i<DEEP; ++i)
        tree[i].num = new int[N+1],
        tree[i].cnt = new int[N+1];
    sorted = new int[N+1];
}

int partition(int A[], int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    int pivotVal = A[pivot];
    swap(A[rht], A[pivot]);

    int smallerIndex = lft; // [lft, smallerIndex) saves the smaller num
    for (int i = lft; i<rht; ++i) {
        if (A[i] < A[rht]) {
            if (i != smallerIndex)
                swap(A[i], A[smallerIndex]);
            smallerIndex++;
        }
    }

    swap(A[smallerIndex], A[rht]);
    return smallerIndex;
}

void qsort(int A[], int lft, int rht) {
    if (lft >= rht) return;

    int pivot = partition(A, lft, rht);
    qsort(A, lft, pivot-1);
    qsort(A, pivot+1, rht);
}


void build(int deep, int lft, int rht) {
    if (lft == rht) return;

    int mid = (lft + rht) / 2, rep_cnt = mid + 1 - lft;

    // @[lft, rht] for sorted[mid]
    for (int i=lft; i<=rht; ++i)
        if (tree[deep].num[i] < sorted[mid]) rep_cnt--;

    int cnt = 0; // @[lft, i] falls into lft tree
    int _l = lft, _r = mid + 1;
    for (int i=lft; i<=rht; ++i) {
        if ( tree[deep].num[i] <  sorted[mid] or
            (tree[deep].num[i] == sorted[mid] and rep_cnt)) {
            if (tree[deep].num[i] == sorted[mid]) rep_cnt--;
            cnt++;
            tree[deep+1].num[_l++] = tree[deep].num[i];
        }
        else tree[deep+1].num[_r++] = tree[deep].num[i];
        tree[deep].cnt[i] = cnt;
    }

    build(deep+1, lft, mid);
    build(deep+1, mid+1, rht);
}

int query(int deep, int lft, int rht, int qlft, int qrht, int k) {
    if (lft == rht) return tree[deep].num[lft];
    if (qlft == qrht) return tree[deep].num[qlft];
    if (qlft == qrht-1) {
        if (tree[deep].num[qlft] < tree[deep].num[qrht]) {
            if (k == 1) return tree[deep].num[qlft];
            else return tree[deep].num[qrht];
        }
        else {
            if (k == 1) return tree[deep].num[qrht];
            else return tree[deep].num[qlft];
        }
    }
    int mid = (lft + rht) / 2, new_qlft, new_qrht, cnt_to_qlft, cnt_query;
    if (qlft == lft) cnt_to_qlft = 0, cnt_query = tree[deep].cnt[qrht];
    else cnt_to_qlft = tree[deep].cnt[qlft-1], cnt_query = tree[deep].cnt[qrht]-cnt_to_qlft;

    if ( k <= cnt_query ) {
        new_qlft = lft + cnt_to_qlft;
        new_qrht = new_qlft + cnt_query - 1;
        query(deep+1, lft, mid, new_qlft, new_qrht, k);
    }
    else {
        int rcnt_to_qlft = qlft - lft - cnt_to_qlft; // @[lft, qlft-1] fall into rtree
        int rcnt_query = qrht - qlft - cnt_query; // @[qlft, qrht] fall into rtree
        new_qlft = mid + 1 + rcnt_to_qlft;
        new_qrht = new_qlft + rcnt_query;
        query(deep+1, mid+1, rht, new_qlft, new_qrht, k - cnt_query);
    }
}

int main(int argc, char const *argv[])
{
    cin >> N;

    init();

    for (int i=1; i<=N; ++i) scanf("%d ", &(tree[0].num[i]));
    for (int i=1; i<=N; ++i) sorted[i] = tree[0].num[i];
    qsort(sorted, 1, N);

    build(0, 1, N);

    for (int i=1; i<=N; i+=2)
        printf("%d\n", query(0, 1, N, 1, i, (i+1)/2 ));

    return 0;
}
