/*
    给定一组数(果子), 每次合并两个数(两堆果子), 消耗的体力为两个数之和
    求最小消耗的体力
    [最小堆]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1e5+5;
int heap[MAX_N];

int N, x, rht = 0;

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
    freopen("sjtu4012/1.in", "r", stdin);
    #endif

    cin >> N;
    for (int i=1; i<=N; ++i) scanf(" %d ", &x), insert(x);

    int combine, ans = 0;
    for (int i=1; i<N; ++i) {
        combine = 0;
        combine += pop();
        combine += pop();
        ans += combine;
        insert(combine);
    }

    printf("%d\n", ans);

    return 0;
}
