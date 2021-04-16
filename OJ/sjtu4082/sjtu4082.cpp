
/*
使用并查集
需要判断不同的连通分量
并计算每隔连通图内部的边数和节点数
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int* parent;
int N, M, u, v, r1, r2, Mtmp;

void init() {
    Mtmp = M;
    parent = new int[N+1];
    for (int i=0; i<=N; ++i) 
        parent[i] = -1;
}

int find(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = find(parent[u]);
}

void union_(int r1, int r2) { // 必须保证 r1, r2 都是 root
    if (r1 == r2) return;
    if (parent[r1] > parent[r2]) // r1.size < r2.size
        parent[r2] += parent[r1], parent[r1] = r2;
    else
        parent[r1] += parent[r2], parent[r2] = r1;
}


long long roads_to_be_built(int u) {
    int nodes = -parent[u];
    return (nodes-1) * nodes / 2;
}

int main(int argc, char const *argv[])
{   
    cin >> N >> M;

    init(); // init disjoint set

    while (Mtmp--) {
        cin >> u >> v;
        r1 = find(u), r2 = find(v);
        union_(r1, r2);
    }

    long long ans = -M;
    for (int i=0; i<=N; ++i)
        if (parent[i] < 0) ans += roads_to_be_built(i);

    cout << ans;
    
    return 0;
}
