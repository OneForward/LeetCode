/*
leet797


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



class Solution {
public:
    VVI allPathsSourceTarget(const VVI& graph) {
        VVI ans;
        VI path;
        int N = graph.size();

        bool visited[20]{};
        function<void(int u)> dfs = [&](int u) {
            path.push_back(u);
            if (u == N-1) {
                ans.push_back(path);
                goto end;
            }
            visited[u] = true;
            for (auto&& v: graph[u]) {
                if (visited[v]) continue;
                dfs(v);
            }
            visited[u] = false;
            end: path.pop_back();
        };
        
        dfs(0);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.allPathsSourceTarget({{1,2}, {3}, {3}, {}}) << endl;
    cout << sol.allPathsSourceTarget({{4,3,1}, {3,2,4}, {3}, {4}, {}}) << endl;
    cout << sol.allPathsSourceTarget({{1}, {}}) << endl;
    cout << sol.allPathsSourceTarget({{1,2, 3}, {2}, {3}, {}}) << endl;
    cout << sol.allPathsSourceTarget({{1,3}, {2}, {3}, {}}) << endl;
    return 0;
}
