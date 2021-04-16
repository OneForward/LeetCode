/*
    实现一个优先级队列
    操作: insert, delete min, get min
    [最小堆]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 2e6+11;
int heap[MAX_N];

int M, x, rht = 0;
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

int pop() {
    int rst = heap[1];
    swap(heap[1], heap[rht]); 

    rht--;
    min_heapify(1);
    return rst;
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu1215/1.in", "r", stdin);
    #endif

    cin >> M;

    while (M--) {
        scanf(" %s ", cache);
        switch (cache[0]) {
            case 'i': scanf(" %d ", &x); insert(x); break;
            case 'd': pop(); break;
            default: printf("%d\n", heap[1]);
        }
    }

    return 0;
}