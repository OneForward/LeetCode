
/*
    DFS求从某一顶点出发到长度为2的简单路径的数目
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

enum COLOR {
    WHITE, GRAY, BLACK
};
arrVertex** graph;
int* visited;
int ans;
int N, M, start, targetLength, a, b;

void init() {
    graph = new arrVertex*[N+1];
    visited  = new int[N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) visited[i] = WHITE;
}

void dfs(int u, int len) {
    if (len == targetLength) { ans++; return; }

    Vertex* v = graph[u]->next;
    visited[u] = GRAY; 
    while (v) {
        if (visited[v->vertex] != GRAY) dfs(v->vertex, len+1);
        v = v->next;
    }
    visited[u] = BLACK;
}

void dfs(int root) { 
    dfs(root, 0);
}


int main(int argc, char const *argv[])
{

    cin >> N >> M >> start >> targetLength;

    init();

    while (M--) {
        cin >> a >> b;
        graph[a]->insert(b);
    }

    dfs(start);

    cout << ans;
    return 0;
}
