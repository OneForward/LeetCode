
/*
    找到所有这样的节点，满足断开该节点后，子树规模的最大值不超过N/2
*/

#include <iostream>
using namespace std;

struct Edge
{
    int vid;   
    Edge* next;
};

struct Vertex
{
    int from; // vertex id
    Edge* next;

    void insert(int to) {
        next = new Edge{to, next};
    }
};



const int MAX_N = 100011;
int N, M, a, b, Mtmp, Ntmp;
Vertex* graph[MAX_N];
int parent[MAX_N];
int sizes[MAX_N];
bool visited[MAX_N] {};


void init() {
    for (int i=0; i<=N; ++i) graph[i] = new Vertex{i};
}

int dfs(int u) {
    visited[u] = true;  
    auto v = graph[u]->next;
    auto cnt = 1;
    while (v) {
        auto vid = v->vid;
        if (not visited[vid]) cnt += dfs(vid), parent[vid] = u;
        v = v->next;
    }
    sizes[u] = cnt;
    return cnt;
}

bool ok(int u) {
    int rest = N-1;
    auto v = graph[u]->next;
    while (v)  {
        auto vid = v->vid; v = v->next;
        if (vid == parent[u]) continue;
        if (sizes[vid] > N/2) return false;
        rest -= sizes[vid]; 
    }
    return rest <= N/2;
}

int main()
{

    // freopen("in.txt", "r", stdin);

    cin >> N;

    init();

    for (int i = 1; i < N; ++i) {
        scanf("%d %d", &a, &b),
        graph[a]->insert(b),
        graph[b]->insert(a);
    }
    
    dfs(1);

    for (int root = 1; root <= N; ++root) {
        if (ok(root)) printf("%d\n", root);
    }

    return 0;
}
