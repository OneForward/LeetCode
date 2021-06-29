/*
leet815


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int numBusesToDestination( vector<vector<int>> routes, int source, int target) {

        auto f = unordered_map<int, vector<vector<int>*>>{};
        for (auto&& bus: routes) {
            for (auto&& x: bus) {
                f[x].push_back(&bus);
            }
        }

        
        if (source == target) return 0;
        auto Q = queue{ deque { source } };
        bool visited[1000005]{}; visited[source] = true;
        for (auto cnt = 1; not Q.empty(); cnt++) {
            for (auto len = Q.size(); len; len--) {
                auto u = Q.front(); Q.pop();
                for (auto&& bus: f[u]) {
                    for (auto&& v: *bus) {
                        if (v == target) { return cnt; }
                        if (visited[v]) continue;
                        Q.push(v); visited[v] = true;
                    }
                    bus->clear();
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numBusesToDestination({{1,7},{3,5}}, 5, 5) << endl;
    cout << sol.numBusesToDestination({{1,2,7},{3,6,7}}, 1, 6) << endl;
    cout << sol.numBusesToDestination({{7,12},{4,5,15},{6},{15,19},{9,12,13}}, 15, 12) << endl;
    cout << sol.numBusesToDestination({{2},{2,8}}, 8, 2) << endl;
    cout << sol.numBusesToDestination({{24},{3,6,11,14,22},{1,23,24},{0,6,14},{1,3,8,11,20}}, 20, 8) << endl;
    return 0;
}
