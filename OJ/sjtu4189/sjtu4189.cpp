
/*
    找到所有这样的节点，满足断开该节点后，子树规模的最大值不超过N/2
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, u, v;
    cin >> N;

    VVI graph(N+1);
    for (int i=1; i<N; ++i) {
        cin >> u >> v;
        graph[u].push_back(v),
        graph[v].push_back(u);
    }

    VI sizes(N+1), parent(N+1);
    vector<bool> visited(N+1);

    function<int(int)> dfs = [&](int root) {
        auto cnt = 1; visited[root] = true;
        for (auto&& v: graph[root]) {
            if (not visited[v]) cnt += dfs(v), parent[v] = root;
        }
        sizes[root] = cnt;
        return cnt;
    };

    dfs(1);

    auto ok = [&](int root) {
        int rest = N-1;
        for (auto&& v: graph[root]) {
            if (v == parent[root]) continue;
            if (sizes[v] > N/2) return false;
            rest -= sizes[v];
        }
        return rest <= N/2;
    };

    for (int root = 1; root <= N; ++root) {
        if (ok(root)) cout << root << "\n";
    }

    return 0;
}
