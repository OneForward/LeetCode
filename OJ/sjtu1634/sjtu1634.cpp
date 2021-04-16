/*
    统计堆排序, 归并排序, 快排的比较次数
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const int MAX_N = 1e6+5;

int A[MAX_N], B[MAX_N], pre[MAX_N], nxt[MAX_N];
int N, k;
long long ans = 0;

void debug() {
    for (int i = 1; i <= N; ++i) printf("%d ", A[i]); 
    printf("\n");
}

bool comp(const int& lhs, const int& rhs) {
    ans++;
    // printf("comparing %d and %d\n", lhs, rhs);
    return lhs < rhs;
}
void merge(int A[], int B[], int lft,  int mid, int rht) {
    int lft1 = lft, rht1 = mid, lft2 = mid+1, rht2 = rht, k = lft;
    while (lft1 <= rht1 and lft2 <= rht2) B[k++] = (comp(A[lft1], A[lft2])) ? A[lft1++] : A[lft2++];
    while (lft1 <= rht1) B[k++] = A[lft1++];
    while (lft2 <= rht2) B[k++] = A[lft2++];
}

void merge_sort(int A[], int lft, int rht) {
    if (lft >= rht) return;
    int mid = (lft + rht - 1) / 2;
    merge_sort(A, lft, mid);
    merge_sort(A, mid+1, rht);
    merge(A, B, lft, mid, rht);
    for (int i=lft; i<=rht; ++i) A[i] = B[i];
}

int partition(int A[], int lft, int rht) { 
    // swap(A[lft], A[rht]);
    // A[lft..j..i..rht]
    int x = A[lft], i = rht;
    for (int j = rht; j > lft; --j) {   
        if (comp(x, A[j])) swap(A[i--], A[j]);
    }
    swap(A[i], A[lft]);
    return i;
}


void qsort(int A[], int lft, int rht) {
    if (lft >= rht) return;
    int mid = partition(A, lft, rht);
    qsort(A, lft, mid-1);
    qsort(A, mid+1, rht);
}

void up(int node) {
    if (node == 1) return;
    if (comp(A[node], A[node/2])) {
        swap(A[node], A[node/2]);
        up(node/2);
    }
}

void down( int pos, int last) {
    if (pos >= last) return;
    int minIndex = pos, lchild = pos * 2, rchild = pos * 2 + 1;
    if (lchild <= last and comp(A[lchild], A[minIndex])) minIndex = lchild;
    if (rchild <= last and comp(A[rchild], A[minIndex])) minIndex = rchild;
    if (minIndex != pos) 
    {
        swap(A[pos], A[minIndex]);
        down(minIndex, last);
    }
}

void heap_sort(int A[], int N) {
    for (int i = 1; i <= N; ++i) up(i);
    for (int i = N; i >= 1; i--)
    {
        swap(A[i], A[1]);
        down(1, i-1);
    }
}

void quick() {
    for (int i = 1; i <= N; i++)
    {
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    nxt[0] = 1;
    pre[N + 1] = N;
    for (int i = N; i >= 1; i--)
    {
        int k = A[i];
        ans += (long long int)(nxt[k] - pre[k] - 2);
        nxt[pre[k]] = nxt[k];
        pre[nxt[k]] = pre[k];
    }
}

int main()
{
    // freopen("in3.txt", "r", stdin);
    cin >> N >> k;
    
    for (int i = 1; i <= N; ++i) scanf(" %d", &A[i]);

    switch (k) {
        case 1: heap_sort(A, N); break;
        case 2: merge_sort(A, 1, N); break;
        // default: qsort(A, 1, N);
        default: quick();
    }
    // debug();
    cout << ans;

    return 0;
}