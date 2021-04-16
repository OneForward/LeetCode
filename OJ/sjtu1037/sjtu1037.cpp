/*
    贪心算法, 快排序+堆排序
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e5+11;

int N, M;
int A[MAX_N], B[MAX_N];

int partition(int arr[], int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    swap(arr[pivot], arr[rht]);
    int pivotVal = arr[rht];

    int smallerIndex = lft;
    for (int i = lft; i < rht; ++i) {
        if (arr[i] >= pivotVal){
            if (i != smallerIndex)
                swap(arr[i], arr[smallerIndex]);
            smallerIndex++;
        }
    }
    swap(arr[smallerIndex], arr[rht]);
    return smallerIndex;
}

void qsort(int arr[], int lft, int rht) {
    if (lft >= rht) return;
    int pivot = partition(arr, lft, rht);
    qsort(arr, lft, pivot-1);
    qsort(arr, pivot+1, rht);
}

// MAX_HEAP

void updateUp(int heap[], int pos) {
    while (pos / 2 and heap[pos/2] < heap[pos]) swap(heap[pos], heap[pos/2]), pos /= 2;
}

void max_heapify(int heap[], int root, int last) {

    int lchild = root * 2;
    if (lchild > last) return;
    int largestIndex = root, rchild = lchild + 1;
    if (heap[largestIndex] < heap[lchild]) largestIndex = lchild;
    if (rchild <= last and heap[largestIndex] < heap[rchild]) largestIndex = rchild;

    if (largestIndex != root)
    {
        swap(heap[largestIndex], heap[root]);
        max_heapify(heap, largestIndex, last);
    }

}

int pop(int heap[], int& last) {
    int max_item = heap[1];
    swap(heap[1], heap[last]);
    max_heapify(heap, 1, --last);
    return max_item;
}

void debug() {
    #ifdef DEBUG

    for (int i=1; i<=N; ++i) printf("%d, ", A[i]); printf("\n");
    for (int i=1; i<=M; ++i) printf("%d, ", B[i]); printf("\n");

    #endif
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG

    freopen("sjtu1037/2.in", "r", stdin);

    #endif

    cin >> N >> M;

    // printf("%d %d\n", N, M);
    for (int i=1; i<=N; ++i) scanf("%d ", &A[i]);
    for (int i=1; i<=M; ++i) scanf("%d ", &B[i]);

    debug();

    qsort(A, 1, N);
    // qsort(B, 0, M-1);

    for (int i=M/2; i>=1; --i) max_heapify(B, i, M);

    debug();

    int ans = 0, Bmax;
    static int last = M;
    for (int i=1; i<=N; ++i) {
        ans++;
        while(last >= 1) {
            Bmax = pop(B, last);
            if (Bmax < A[i]) {
                ans++;
                break;
            }
        }
    }

    debug();
    printf("%d", ans);
    return 0;
}
