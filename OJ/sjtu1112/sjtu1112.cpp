/*
    堆, 堆排序, extract_max(), push(x), max_heapify()操作
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 1011;
int N, K;

int  weights[MAX_N], heapArray[MAX_N];
bool visited[MAX_N];
bool neighbors[MAX_N][MAX_N];

void max_heapify(int A[], int B[], int start, int last) { // comp by B[A[i]], A is heapArray indexed from B
    int maxIndex = start, lchild = start * 2;
    if (lchild > last) return;
    if (B[A[lchild]] > B[A[maxIndex]]) maxIndex = lchild;
    if (lchild+1 <= last and B[A[lchild+1]] > B[A[maxIndex]]) maxIndex = lchild+1;
    if (maxIndex != start) {
        swap(A[start], A[maxIndex]);
        max_heapify(A, B, maxIndex, last);
    }
}

int extract_max(int A[], int B[], int& last) { // 返回最大值的Index
    swap(A[1], A[last]);
    max_heapify(A, B, 1, --last);
    return A[last+1];
}

int push(int A[], int B[], int& last, int x) {
    A[++last] = x;
    int p = last;
    while (p/2 >= 1 and B[A[p/2]] < B[A[p]]) swap(A[p/2], A[p]), p /= 2;
}

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    for (int i=1; i<=N; ++i)
        scanf("%d", &weights[i]);

    for (int i=1; i<=K; ++i) scanf("%d", &heapArray[i]);
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
            scanf("%d", &neighbors[i][j]);
    for (int i=1; i<=K; ++i) visited[heapArray[i]] = true;

    for (int i=K/2; i>=1; --i) max_heapify(heapArray, weights, i, K);
    
    int last = K, maxIndex, Ntmp = N;
    while (Ntmp--){
        maxIndex = extract_max(heapArray, weights, last);
        printf("%d\n", maxIndex);
        for (int j=1; j<=N; ++j)
            if (neighbors[maxIndex][j] and not visited[j])
                visited[j] = true,
                push(heapArray, weights, last, j);
    }
    return 0;
}
