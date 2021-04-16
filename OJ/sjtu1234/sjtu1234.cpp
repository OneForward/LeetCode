
/*
    Kruskal 最小生成树算法
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
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
        next = new Vertex(from, to, weight, next);
    }
    int getEdgeWeight(int to) {
        Vertex* vnode = next;
        while (vnode and vnode->vertex != to) vnode = vnode->next;
        return vnode->weight;
    }
};

struct CompareByWeight
{
    bool operator() (const Vertex* lhs, const Vertex* rhs)
        { return lhs->weight < rhs->weight; }
};

enum COLOR {
    WHITE, GRAY, BLACK
};
arrVertex** graph;
Vertex** edges;
int ans = 0;
int N, M, a, b, p, Mtmp;
int* parent;

void init() {
    Mtmp = M;
    graph = new arrVertex*[N+1];
    edges = new Vertex*[M];
    parent = new int[N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) parent[i] = -1;
}


template <class T, class Comp=less<T>>
int partition(T* A, int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    T pivotVal = A[pivot];
    swap(A[pivot], A[rht]);

    int storeIndex = lft;
    for (int i = lft; i < rht; ++i)
        if (Comp()(A[i], pivotVal))
            swap(A[storeIndex], A[i]), storeIndex++;
    swap(A[rht], A[storeIndex]);
    return storeIndex;
}

template <class T, class Comp=less<T>>
void qsort(T* A, int lft, int rht) {
    if (lft >= rht) return;
    int pivot = partition<T, Comp>(A, lft, rht);
    qsort<T, Comp>(A, lft, pivot-1);
    qsort<T, Comp>(A, pivot+1, rht);
}

int find(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

void Union(int r1, int r2) { // r1, r2 一定不相等
    if (parent[r1] > parent[r2]) // r1.size < r2.size
        parent[r2] += parent[r1], parent[r1] = r2;
    else
        parent[r1] += parent[r2], parent[r2] = r1;
}

int main(int argc, char const *argv[])
{

    cin >> N >> M;

    init();

    while (Mtmp--) {
        cin >> a >> b >> p;
        graph[a]->insert(b, p);
        graph[b]->insert(a, p);
        edges[Mtmp] = new Vertex(a, b, p);
    }
    debug();
    qsort<Vertex*, CompareByWeight>(edges, 0, M-1);

    Vertex* u;
    int root1, root2, cnt = 0, ans = 0;
    for (int i=0; i<M; ++i) {
        u = edges[i];
        root1 = find(u->from);
        root2 = find(u->vertex);
        if (root1 == root2) continue;
        Union(root1, root2); ans += u->weight; 
        if (++cnt == N-1) break;
    }

    cout << ans;
    return 0;
}

