/*
    给定 A[1..N], B[1..N], 求两数列的N^2种和中最小的前N项
    [快排+堆]
    对 A, B 快排排序, 对相加的和采用最小优先队列, pop最小者, push最小者对应的索引附近的数
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct Node
{
    int idxA;
    int val;
    Node(int iA=0, int v=0): idxA(iA), val(v) {}
};

struct SmallerNode
{
    bool operator() (const Node& lhs, const Node& rhs) { return lhs.val < rhs.val; }
};

int N;
int* A, *B, *C;
Node* rst;

void init() {
    A = new int[N+1];
    B = new int[N+1];
    C = new int[N+1];
    rst = new Node[N+1];
    for (int i=1; i<=N; ++i) C[i] = 1;
}

template <class T, class Comp>
void push(T heap[], int& rht, T x) {
    heap[++rht] = x;
    int p = rht;
    while (p/2 and Comp()(heap[p], heap[p/2])) swap(heap[p], heap[p/2]), p /= 2;
}

template <class T, class Comp>
void heapify(T heap[], int root, int rht) {
    int compIndex = root, lchld = 2 * root;
    if (lchld > rht) return;
    if (Comp()(heap[lchld], heap[compIndex])) compIndex = lchld;
    if (lchld < rht and Comp()(heap[lchld+1], heap[compIndex])) compIndex = lchld+1;

    if (compIndex != root) {
        swap( heap[compIndex], heap[root] );
        heapify<T, Comp>(heap, compIndex, rht);
    }
}

template <class T, class Comp>
T pop(T heap[], int& rht) {
    T ret = heap[1];
    swap(heap[1], heap[rht]);
    heapify<T, Comp>(heap, 1, --rht);
    return ret;
}

int partition(int arr[], int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    int pivotVal = arr[pivot];
    swap(arr[pivot], arr[rht]);

    int smallerIndex = lft; // [lft, smallerIndex) is consistently less than pivotVal
    for (int i=lft; i<rht; ++i) {
        if (arr[i] < pivotVal) {
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

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu4171/1.in", "r", stdin);
    #endif // DEBUG

    cin >> N;

    init();

    for (int i=1; i<=N; ++i) scanf(" %d ", &A[i]);
    for (int i=1; i<=N; ++i) scanf(" %d ", &B[i]);

    qsort(A, 1, N);
    qsort(B, 1, N);
 
    int Ntmp = N, i = 1, rstRht = 0;
    Node minNode;
    push<Node, SmallerNode>(rst, rstRht, Node(i, A[i]+B[C[i]++]));
    while (Ntmp--) {
        minNode = pop<Node, SmallerNode>(rst, rstRht);
        printf("%d ", minNode.val);
        i = minNode.idxA;
        push<Node, SmallerNode>(rst, rstRht, Node(i, A[i]+B[C[i]++]));

        i++;
        if (i <= N and C[i] <= N)
            push<Node, SmallerNode>(rst, rstRht, Node(i, A[i]+B[C[i]++]));
    }
    return 0;
}
