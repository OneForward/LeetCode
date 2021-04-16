/*
    归并排序的归并操作
    merge A[0,..,mid], A[mid+1,...,rht]
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const int MAX_N = 1e6+5;

int A[MAX_N], B[MAX_N], lenA, lenB;

void merge(int A[], int mid, int rht) { // merge A[0,..,mid], A[mid+1,...,rht]
    int k = 0, start1 = 0, end1 = mid, start2 = mid+1, end2 = rht;
    while (start1 <= end1 and start2 <= end2) 
        B[k++] = (A[start1] < A[start2]) ? A[start1++] : A[start2++];
    while (start1 <= end1) B[k++] = A[start1++];
    while (start2 <= end2) B[k++] = A[start2++];
}

int main(int argc, char const *argv[])
{
    cin >> lenA >> lenB;
    for (int i=0; i<lenA+lenB; ++i) scanf("%d", &A[i]);
    
    merge(A, lenA-1, lenA+lenB-1);
    
    for (int i=0; i<lenA+lenB; ++i) printf("%d ", B[i]);
    return 0;
}