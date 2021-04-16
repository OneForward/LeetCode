#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

template <class T, class Comp>
struct PriorityQueue // 小根堆
{
    T* arr;
    int _end, MAX_SIZE;
    PriorityQueue(int N):_end(1), MAX_SIZE(N+1) { arr = new int[MAX_SIZE]; }
    ~PriorityQueue() { delete [] arr; }

    int parent(int u) { return u / 2; }
    int lchild(int u) { return u * 2; }
    int rchild(int u) { return u * 2 + 1; }

    void push(int x) {
        int u = _end;
        arr[_end++] = x;
        while (parent(u) and Comp()(arr[u], arr[parent(u)]))
            swap(arr[u], arr[parent(u)]), u = parent(u);
    }

    void min_heapify(int start, int last) {
        int smallestIndex = start;
        int child = start * 2;
        if (child > last)
            return;
        if (Comp()(arr[child], arr[smallestIndex]))
            smallestIndex = child;
        if (child+1 < _end and Comp()(arr[child+1], arr[smallestIndex]))
            smallestIndex = child+1;
        if (smallestIndex != start)
        {
            swap(arr[smallestIndex], arr[start]);
            min_heapify(smallestIndex, last);
        }
    }
    T extract_min() {
        min_heapify(1, _end-1);
        T minNodeIndex = arr[1]; arr[1] = arr[--_end];
        min_heapify(1, _end-1);
        return minNodeIndex;
    }

    bool isempty() { return _end == 1; }
    bool isfull() { return _end == MAX_SIZE; }
};

int main(int argc, char const *argv[])
{
    const int N = 10;
    PriorityQueue<int, less<int>> Q(N);
    while (not Q.isfull())
        Q.push(rand() % (N*N));
    while (not Q.isempty()) 
        cout << setw(6) << Q.extract_min() ;
    return 0;
}