#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAX_N = 9;
int A[MAX_N+1] = {};

int next_permutate() {
    int partitionNum = MAX_N-1, changeNum = MAX_N;
    while (partitionNum >= 1 and A[partitionNum] > A[partitionNum+1]) partitionNum--;
    while (changeNum > partitionNum and A[changeNum] < A[partitionNum]) changeNum--;
    swap(A[changeNum], A[partitionNum]); //printf("P = %d, C = %d\n", partitionNum, changeNum);
    for (int i = 1; i <= (MAX_N-partitionNum)/2; ++i)
        swap(A[partitionNum+i], A[MAX_N+1-i]);
    
    return partitionNum;
}

int main(int argc, char const *argv[])
{
    for (int i=1; i<=MAX_N; ++i) A[i] = i;
    freopen("perm.out", "w", stdout);
    while (next_permutate() != 0)
        { for (int i=1; i<=MAX_N; ++i) cout << setw(4) << A[i]; cout << endl; }
    return 0;
}