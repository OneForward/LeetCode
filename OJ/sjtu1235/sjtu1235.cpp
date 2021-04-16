/*
    Dijkstra 单源最短路径算法
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Vertex
{
    int from;
    int vertex;    // vertex num of self
    int weight;
    Vertex* next;
    Vertex(int _f, int _t, int _w=0, Vertex* _n=nullptr)
        :from(_f), vertex(_t), weight(_w), next(_n) {}
    ~Vertex() {}
};

struct arrVertex
{
    int from;
    Vertex* next;
    arrVertex(int _f, Vertex* _n=nullptr):from(_f), next(_n) {}
    ~arrVertex() {}

    void insert(int to, int weight=0) {
        if (from == to) return;
        Vertex* vnode = next;
        while (vnode and vnode->vertex != to) vnode = vnode->next;
        if (vnode == nullptr) next = new Vertex(from, to, weight, next);
        else if (weight < vnode->weight) vnode->weight = weight;
    }
};

template <class Comp>
struct PriorityQueue // 小根堆
{
    int* arr;
    int _end, MAX_SIZE;
    PriorityQueue(int N):_end(1), MAX_SIZE(N+1) { arr = new int[MAX_SIZE]; }
    ~PriorityQueue() { delete [] arr; }

    int parent(int u) { return u / 2; }

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

    int extract_min() {
        int minNodeIndex = arr[1]; arr[1] = arr[--_end];
        min_heapify(1, _end-1);
        return minNodeIndex;
    }

    bool isempty() { return _end == 1; }
};


arrVertex** graph;
int N, M, start, dst, a, b, p, Mtmp;
long long* Dist;
int* prevNode;
int* hops;
const long long INF = 0x7FFFFFFF;

struct CompareByDist
{
   bool operator() (int u, int v) { return Dist[u] < Dist[v]; }
};
PriorityQueue<CompareByDist>* Q;

void init() {
    Mtmp = M;
    Dist = new long long [N+1];
    for (int i=1; i<=N; ++i) Dist[i] = INF;
    Dist[start] = 0;
    Q = new PriorityQueue<CompareByDist>(M);
    Q->push(start);

    graph = new arrVertex*[N+1];
    prevNode = new int [N+1];
    hops     = new int [N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) prevNode[i] = -1, hops[i] = 0;
}


void relax(Vertex* edge) {
    int u = edge->from, v = edge->vertex, w = edge->weight;
    if (Dist[v] > Dist[u] + w or (Dist[v] == Dist[u] + w and hops[v] > hops[u]))
        Dist[v] = Dist[u] + w, prevNode[v] = u, hops[v] = hops[u] + 1, Q->push(v);
}

int main(int argc, char const *argv[])
{
    cin >> N >> M >> start >> dst;

    init();

    while (Mtmp--) {
        scanf("%d%d%d", &a, &b, &p);
        graph[a]->insert(b, p);
    }

    int u;
    Vertex* v;
    while (not Q->isempty()) { // Dijkstra
        u = Q->extract_min(); 
        v = graph[u]->next;
        while (v)  {
            relax(v);
            v = v->next;
        }
    }

    cout << Dist[dst] << endl;

    u = prevNode[dst];
    int* links = new int[N+1]; int cnt = 0;
    while (u >= 0) links[cnt++] = u, u = prevNode[u];
    while (cnt--) printf("%d ", links[cnt]); cout << dst;
    return 0;
}

