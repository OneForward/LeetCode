/*
leet787


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;




using VI=vector<int>;
using ipair=pair<int,int>;
using VP = vector<ipair>;
using VVP = vector<VP>;
using Tuple = tuple<int, int, int>;
using VT = vector<Tuple>;
class Solution {
public:
    int findCheapestPrice(int N, const vector<vector<int>>& flights, int src, int dst, int K) {
        // Dijkstra, 不能使用 visited 和 cost 数组
        VVP graph(N);
        for (auto&& e: flights) {
            auto u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
        }

        priority_queue Q(greater<Tuple>{}, VT{});
        Q.emplace(0, 0, src); 
        while (Q.size()) {
            auto [f, len, u] = Q.top(); Q.pop();
            if (u == dst) return f;
            if (len > K) continue;
            for (auto&& [v, w]: graph[u] ) {
                Q.emplace( f + w, len + 1, v );
            }
        }
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findCheapestPrice(3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 1) << endl;
    cout << sol.findCheapestPrice(3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 0) << endl;
    cout << sol.findCheapestPrice(4, {{0,1,1},{0,2,5},{1,2,1},{2,3,1}}, 0, 3, 1) << endl;
    cout << sol.findCheapestPrice(5, {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}}, 0, 2, 2) << endl;
    return 0;
}
