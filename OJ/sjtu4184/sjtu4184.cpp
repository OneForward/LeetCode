/*
通过dfs遍历全树并记录每个节点所对应的子树的规模
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
    Vertex(int _f, int _t, int _w, Vertex* _n=nullptr)
        :from(_f), vertex(_t), weight(_w), next(_n) {}
    ~Vertex() {}
};

struct arrVertex
{
    int from;
    Vertex* next;
    arrVertex(int _f, Vertex* _n=nullptr):from(_f), next(_n) {}
    ~arrVertex() {
        Vertex* tmpNode = next;
        while (tmpNode) {
            next = next->next;
            delete tmpNode;
            tmpNode = next;
        }
    }

    void insert(int to, int weight=0) {
        next = new Vertex(from, to, weight, next);
    }
};
enum COLOR {WHITE, GRAY, BLACK, RED};
arrVertex** graph;
int T, N, K, P, u, v, Ntmp;
int* visited;
int* treesize;

void init() {
    Ntmp = N-1; P = 0;
    graph = new arrVertex*[N+1];
    visited  = new int[N+1];
    treesize  = new int[N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) treesize[i] = 1, visited[i] = WHITE;
}

void clearMemory() {
    if (graph) {
        for (int i=0; i<=N; ++i)
            if (graph[i]) delete graph[i];
        delete [] graph;
    }
    delete visited;
    delete treesize;
}

void dfs(int u) {
    visited[u] = GRAY;
    Vertex* v = graph[u]->next;
    while (v) {
        if (visited[v->vertex] == WHITE)
            dfs(v->vertex);
        if (visited[v->vertex] == BLACK) {
            if (treesize[v->vertex] == K) P++;
            else treesize[u] += treesize[v->vertex];
        }
        v = v->next;
    }
    visited[u] = BLACK;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        init();
        while (Ntmp--) {
            scanf("%d %d", &u, &v);
            graph[u]->insert(v);
            graph[v]->insert(u);
        }
        if (N % K) { printf("NO\n"); clearMemory(); continue; }
        if (K == 1 or K == N){ printf("YES\n"); clearMemory(); continue; }
        dfs(1);
        if (P == N/K-1) printf("YES\n");
        else printf("NO\n");
        clearMemory();
    }
    return 0;
}
