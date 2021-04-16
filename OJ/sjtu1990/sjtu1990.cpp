/*
    问询：最小值位置
    动作：单点自增自减
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;


const int MAX_N = 1e5 + 11;

int N, M, pos, x;
int A[MAX_N];

int getMinIndex(int changed) {
    int minIdx, minVal = A[1];
    for (int i=1; i<=N; ++i)
        if ( A[i] <  minVal or
            (A[i] == minVal and i <= changed) ) minVal = A[i], minIdx = i;
    return minIdx;
}

void debug() {
    #ifdef DEBUG

    for (int i=1; i<=N; ++i) printf("%d, ", A[i]); printf("\n");

    #endif
}


int main(int argc, char const *argv[])
{
    #ifdef DEBUG

    freopen("sjtu1990/1.in", "r", stdin);

    #endif

    cin >> N >> M;
    for (int i=1; i<=N; ++i) scanf("%d ", &A[i]);

     // debug();

    int minIdx;
    while (M--) {
        scanf("%d %d ", &pos, &x);
        A[pos] += x;
        minIdx = getMinIndex( pos );
        // if (A[minIdx] == A[pos] ) printf("%d\n", pos);
         printf("%d", minIdx);
         if (M) printf("\n");
    }


    return 0;
}
