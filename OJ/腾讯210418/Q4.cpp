#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

bool visited[200005] {};

void dfs(VVI& graph, int root) {
    cout << root << " "; visited[root] = true;
    for (auto&& v: graph[root]) {
        if (not visited[v]) dfs(graph, v);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M, u, v;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        memset(visited, 0, sizeof visited);
        VVI graph(N+1);
        while (M--) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (auto&& edge: graph) sort(edge.begin(), edge.end());

        dfs(graph , 1); cout << "\n";
    }
    
    return 0;
}
