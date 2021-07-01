/*
lcp07


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int numWays(int n, const vector<vector<int>>& relation, int k) {
        int f[10]{1}, g[10]{};
        while (k--) {
            for (auto&& e: relation) {
                g[e[1]] += f[e[0]];
            }
            memcpy(f, g, sizeof g);
            memset(g, 0, sizeof g);
        }
        return f[n-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numWays(5,   {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}},  3) << endl;
    cout << sol.numWays(3,   {{0,2},{2,1}},  2) << endl;
    return 0;
}
