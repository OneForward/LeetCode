/*
    Matrix Sum: 求奇子阵的总数
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 405;

int N, x;
int A[MAX_N][MAX_N] = {};


void debug() {
    #ifdef DEBUG

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) 
            printf("%d ", A[i][j]);
        printf("\n");
    }

    #endif
}


int main(int argc, char const *argv[])
{
    #ifdef DEBUG

    freopen("sjtu1228/1.in", "r", stdin);

    #endif

    scanf("%d ", &N);
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j) scanf("%d ", &x), A[i][j] = ( x & 1);

    // debug();

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) 
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
    }
    
    int oddCnt = 0, sumSubMat;
    for (int r1 = 1; r1 <= N; ++r1) {
        for (int r2 = r1; r2 <= N; ++r2) {
            for (int c1 = 1; c1 <= N; ++c1) {
                for (int c2 = c1; c2 <= N; ++c2) {
                    sumSubMat = A[r2][c2] - A[r1-1][c2] + A[r1-1][c1-1] - A[r2][c1-1];
                    if ((sumSubMat) & 1) oddCnt++;
                }
            }
        }
    }


    // debug();

    printf("%d %d", oddCnt, N*(N+1)/2*N*(N+1)/2 - oddCnt);
    // printf("cnt = %d \n", cnt);
    return 0;
}