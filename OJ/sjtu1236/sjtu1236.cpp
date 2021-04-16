
/*
    Bellman-Ford 单源最短路径算法
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
        if (from == to) return;
        Vertex* vnode = next;
        while (vnode and vnode->vertex != to) vnode = vnode->next;
        if (vnode == nullptr) next = new Vertex(from, to, weight, next);
        else if (weight < vnode->weight) vnode->weight = weight;
    }
    int getEdgeWeight(int to) {
        Vertex* vnode = next;
        while (vnode and vnode->vertex != to) vnode = vnode->next;
        return vnode->weight;
    }
};


arrVertex** graph;
Vertex** edges;
int N, M, start, _end, a, b, p, Mtmp, Ntmp;
int* Dist;
int* prevNode;
const int INF = 0x1FFFFFFF;

void init() {
    Mtmp = M; Ntmp = N;
    Dist = new int [N+1];
    for (int i=1; i<=N; ++i) Dist[i] = INF;
    Dist[start] = 0;

    graph = new arrVertex*[N+1];
    edges = new Vertex*[M+1];
    prevNode = new int [N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) prevNode[i] = -1;
}

void relax(Vertex* edge) {
    int u = edge->from, v = edge->vertex, w = edge->weight;
    if (Dist[v] > Dist[u] + w)
        Dist[v] = Dist[u] + w, prevNode[v] = u;
}

int main(int argc, char const *argv[])
{

    cin >> N >> M >> start >> _end;

    init();

    while (Mtmp--) {
        cin >> a >> b >> p;
        graph[a]->insert(b, p);
        edges[Mtmp] = new Vertex(a, b, p);
    }

    while (Ntmp--)
        for (int i=0; i<M; ++i)
            relax(edges[i]);

    cout << Dist[_end];
    return 0;
}

