/*
    实现一个优先级队列
    操作: insert, decrease key, find x(大于x的最小的数字下标)
    [最小堆]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 2e6+11;
int heap[MAX_N];

int M, node, x, rht = 0;
char cache[10];

void min_heapify(int t) {
    int lchild = 2*t;
    if (lchild > rht) return;

    int minIndex = t, rchild = lchild + 1;
    if (heap[lchild] < heap[minIndex]) minIndex = lchild;
    if (rchild <= rht and heap[rchild] < heap[minIndex]) minIndex = rchild;
    if (minIndex != t) {
        swap(heap[t], heap[minIndex]);
        min_heapify(minIndex);
    }
}

void insert(int x) {
    heap[++rht] = x;
    int p = rht;
    while (p/2 and heap[p] < heap[p/2]) swap(heap[p], heap[p/2]), p /= 2;
}

void decrease_key(int node, int x) {
    heap[node] -= x;
    int p = node;
    while (p/2 and heap[p] < heap[p/2]) swap(heap[p], heap[p/2]), p /= 2;
}

int find(int x) {
    int ans = 1, curMin=0x7FFFFFFF;
    for (int i=1; i<=rht; ++i)
        if (x < heap[i] and heap[i] < curMin) curMin = heap[i], ans = i;
    return ans;
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1216/1.in", "r", stdin);
    #endif

    cin >> M;

    while (M--) {
        scanf(" %s ", cache);
        switch (cache[0]) {
            case 'i': scanf(" %d ", &x); insert(x); break;
            case 'd': scanf(" %d %d ", &node, &x); decrease_key(node, x); break;
            default: scanf(" %d ", &x); printf("%d\n", find(x));
        }
    }

    return 0;
}
