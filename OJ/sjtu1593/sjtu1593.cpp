/*
struct Mouse
{
    int index;
    int points;
    int strength;
};
mergeSort() + bubbleSort()
mergeSort() 可以换成 qsort(), 注意 Cmp() 类的书写
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <functional>
using namespace std;

struct Mouse
{
    int index;
    int points;
    int strength;
    Mouse(int i=0, int p=0, int s=0): index(i), points(p), strength(s) {}
};

static int compare_cnt = 0;
struct CompareMouseByPoints
{
    bool operator() (const Mouse* lhs, const Mouse* rhs) {
        compare_cnt++;
        if (lhs->points < rhs->points) return true;
        if (lhs->points == rhs->points) return lhs->index > rhs->index;
        return false;
    }
};

Mouse** Mice;

int N, R, cnt = 0;

void init() {
    Mice = new Mouse*[2*N+1];
    for (int i=1; i<=2*N; ++i) Mice[i] = new Mouse(i);
}

template <class T, class Comp=less<T>>
void merge_sort_recursive(T* A, T* B, int lft, int rht) {
    if (lft >= rht) return;
    int mid = (lft + rht) / 2;
    merge_sort_recursive<T, Comp>(A, B, lft, mid);
    merge_sort_recursive<T, Comp>(A, B, mid+1, rht);

    int start1 = lft, end1 = mid, start2 = mid + 1, end2 = rht, k = lft;
    while (start1 <= end1 and start2 <= end2)
        B[k++] = !Comp()(A[start1], A[start2]) ? A[start1++] : A[start2++];
    while (start1 <= end1) B[k++] = A[start1++];
    while (start2 <= end2) B[k++] = A[start2++];

    for (k = lft; k <= rht; ++k) A[k] = B[k];
}

template <class T, class Comp=less<T>>
void merge_sort(T* A, int lft, int rht) {
    T* B = new T[rht+1];
    merge_sort_recursive<T, Comp>(A, B, lft, rht);
}

template <class T, class Comp=less<T>>
void bubbleSort(T* A, int lft, int rht) {
    bool exist_swap;
    for (int i=rht; i>=lft; --i) {
        exist_swap = false;
        for (int j=lft; j<i; ++j) {
            if (Comp()(A[j], A[j+1])) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (not exist_swap) break;
    }
}


int main(int argc, char const *argv[])
{

    cin >> N >> R;
    
    init();

    for (int i=1; i<=2*N; ++i) scanf("%d ", &(Mice[i]->points));
    for (int i=1; i<=2*N; ++i) scanf("%d ", &(Mice[i]->strength));

    merge_sort<Mouse*, CompareMouseByPoints>(Mice, 1, 2*N);
    
    while (R--) {
        for (int i=1; i<=2*N; i+=2) {
            if (Mice[i]->strength > Mice[i+1]->strength) Mice[i]->points += 2;
            else if (Mice[i]->strength < Mice[i+1]->strength) Mice[i+1]->points += 2;
            else Mice[i]->points++, Mice[i+1]->points++;
        }
        bubbleSort<Mouse*, CompareMouseByPoints>(Mice, 1, 2*N);\
    }

    for (int i=1; i<=2*N; ++i) cout << Mice[i]->index << " ";
    return 0;
}

