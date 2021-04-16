
/*
    哈夫曼树, K叉, 计算最终的带权路径长度(WPL)
    K-way HauffmanTree, heap
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <functional>
using namespace std;

const int MAX_N = 200005;

int N, M, Mtmp;
int freq[MAX_N] = {};

template <class T, class Comp=std::less<T>>
void min_heapify(T A[], int start, int last) {
    int smallestIndex = start, lchild = start * 2;
    if (lchild > last) return;
    if (Comp() (A[lchild], A[smallestIndex])) smallestIndex = lchild;
    if (lchild+1 <= last and Comp() (A[lchild+1], A[smallestIndex])) smallestIndex = lchild+1;
    if (smallestIndex != start) {
        swap(A[smallestIndex], A[start]);
        min_heapify<T, Comp>(A, smallestIndex, last);
    }
}

int main(int argc, char const *argv[])
{

    cin >> N >> M;
    int remainder = (M - 1) - (N - 1) % (M - 1) ;
    if (remainder == M-1) remainder = 0;

    N += remainder;
    for (int i=remainder+1; i<=N; ++i) scanf("%d", &freq[i]);
    for (int i=N/2; i>=1; --i) min_heapify<int>(freq, i, N);
    
    int last = N;
    long long ans = 0;
    while (last > 1) {
        Mtmp = M;
        while (Mtmp--) {
            swap(freq[1], freq[last]);
            min_heapify<int>(freq, 1, --last);
        }
    
        last++;
        for (int i=1; i<=M-1; ++i) freq[last] += freq[last+i];
        ans += freq[last];
        int p = last;
        while (p/2 >= 1 and freq[p/2] > freq[p]) swap(freq[p/2], freq[p]), p /= 2;
    }

    cout << ans;
    return 0;
}
