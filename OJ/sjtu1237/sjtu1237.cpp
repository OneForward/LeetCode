/*
    Topological Sort 拓扑排序
*/

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

struct Vertex
{
    int from;
    int vertex;    // vertex num of self
    Vertex* next;
    Vertex(int f, int t, Vertex* n=nullptr)
        :from(f), vertex(t), next(n) {}
    ~Vertex() {}
};

struct arrVertex
{
    int from;
    Vertex* next;
    arrVertex(int f, Vertex* n=nullptr):from(f), next(n) {}
    ~arrVertex() {}

    void insert(int to) {
        next = new Vertex(from, to, next);
    }
};

struct Node
{
    int vertex;
    Node* next;
    Node(int v=0, Node* n=nullptr): vertex(v), next(n) {}
};

struct list
{
    Node* head;
    list(): head(new Node()) {}
    ~list() { delete head; }

    void push_front(int x) { head->next = new Node(x, head->next); }

    void remove(Node* p) { // 实际上remove的是p->next
        Node* tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
    bool isempty() { return head->next == nullptr; }
};

enum COLOR {
    WHITE, GRAY, BLACK
};
arrVertex** graph;
int N, M, start, _end, a, b, p, Mtmp, Ntmp;
int* visited;
int* indegree;
int* copyIndegrees;
list L;

void init() {
    Mtmp = M; Ntmp = N;

    graph = new arrVertex*[N+1];
    visited = new int [N+1];
    indegree = new int [N+1];
    copyIndegrees = new int[N+1];
    for (int i=0; i<=N; ++i) graph[i] = new arrVertex(i);
    for (int i=0; i<=N; ++i) indegree[i] = 0, visited[i] = WHITE;
}

void dfs(int u) {
    visited[u] = GRAY; 
    Vertex* v = graph[u]->next;
    while (v) {
        if (visited[v->vertex] == WHITE) dfs(v->vertex);
        v = v->next;
    }
    visited[u] = BLACK;
    L.push_front(u);
}

void dfs() {
    for (int u=1; u<=N; ++u)
        if (visited[u] == WHITE) dfs(u);
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    init();

    while (Mtmp--) {
        cin >> a >> b;
        graph[a]->insert(b);
        indegree[b]++;
    }

    dfs();

    int ans = 0;
    Node* p;
    Vertex* v;
    
    for (int i=1; i<=N; ++i) copyIndegrees[i] = indegree[i];
    while (not L.isempty()) {
        p = L.head;
        while (p->next) {
            if (copyIndegrees[p->next->vertex] == 0) {
                v = graph[p->next->vertex]->next;
                while (v) {
                    indegree[v->vertex]--;
                    v = v->next;
                }
                L.remove(p);
            }
            else p = p->next;
        }
        for (int i=1; i<=N; ++i) copyIndegrees[i] = indegree[i];
        ans++;
    }

    cout << ans;
    return 0;
}

