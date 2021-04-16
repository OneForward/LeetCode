
/*
求一棵树中到三个节点距离之和最短的节点
将其视为寻找公共祖先的问题
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
    ~arrVertex() {}

    void insert(int to, int weight) {
        next = new Vertex(from, to, weight, next);
    }
    int getEdgeWeight(int to) {
        Vertex* vnode = next;
        while (vnode and vnode->vertex != to) vnode = vnode->next;
        return vnode->weight;
    }
};

arrVertex** graph;
int* min_dist;
bool* visited;
int* ans;
int N, A, B, C, u, v, w, num = 1;
int* pathAB, *pathAC;
int lenAB = 0, lenAC = 0;

void init() {
    graph = new arrVertex*[N+1];
    min_dist = new int[N+1];
    ans      = new int[N+1];
    visited  = new bool[N+1];
    pathAB   = new int[N+1];
    pathAC   = new int[N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) min_dist[i] = 0, ans[i] = 0, visited[i] = false;
}

void _dfs(int u, int x, bool& found, int* path, int& len) {
    Vertex* vnode = graph[u]->next;
    visited[u] = true;
    while (vnode) {
        if (vnode->vertex == x) { found = true; path[len] = vnode->vertex; len++; return; }
        if (not visited[vnode->vertex]) _dfs(vnode->vertex, x, found, path, len);
        if (found) { path[len] = vnode->vertex; len++; return; }
        vnode = vnode->next;
    }
}

void dfs(int root, int x, int* path, int& len) { // search x
    for (int i=0; i<=N; ++i) min_dist[i] = 0, visited[i] = false;
    bool found = false;
    _dfs(root, x, found, path, len);
    path[len] = root; len++;
}

int main(int argc, char const *argv[])
{
    #ifdef DEBUG
    freopen("sjtu4119/.in", "r", stdin);
    #endif // DEBUG

    cin >> N >> A >> B >> C;

    init();

    while (num < N) {
        cin >> u >> v >> w;
        graph[u]->insert(v, w);
        graph[v]->insert(u, w);
        num++;
    }
    
    dfs(A, B, pathAB, lenAB);
    dfs(A, C, pathAC, lenAC);

    int commonVertex, minimum_distance = 0, index = 1;
    while (pathAB[lenAB-index] == pathAC[lenAC-index]) index++;
    index--;

    commonVertex = pathAB[lenAB-index];
    for (int i=1; i<index; ++i) minimum_distance += graph[pathAB[lenAB-i]]->getEdgeWeight(pathAB[lenAB-i-1]);
    for (int i=index; i<lenAB; ++i) minimum_distance += graph[pathAB[lenAB-i]]->getEdgeWeight(pathAB[lenAB-i-1]);
    for (int i=index; i<lenAC; ++i) minimum_distance += graph[pathAC[lenAC-i]]->getEdgeWeight(pathAC[lenAC-i-1]);
    cout << commonVertex << endl;
    cout << minimum_distance;
    return 0;
}

