/*
lcp35


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
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;

using ipair=pair<int,int>;
using VI=vector<int>;
using VVI=vector<VI>;
using VP=vector<ipair>;
using VVP=vector<VP>;

using Tuple=tuple<int, int, int>;
using VT=vector<Tuple>;
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n = charge.size();
        VVP edges(n);
        for (auto&& e: paths) {
            edges[e[0]].emplace_back(e[1], e[2]);
            edges[e[1]].emplace_back(e[0], e[2]);
        }


        VVI dist(n, VI(cnt + 1, INT_MAX / 2));
        dist[start][0] = 0;
        
        priority_queue Q(greater{}, VT{});
        Q.emplace(0, start, 0);

        while (Q.size()) {
            auto [d, u, power] = Q.top(); Q.pop();

            if (d > dist[u][power]) continue;

            if (u == end) return d;

            if (power < cnt) {
                auto newd = d + charge[u] ;
                if (newd < dist[u][power + 1]) {
                    dist[u][power + 1] = newd;
                    Q.emplace(newd, u, power + 1);
                }
            }
            
            for (auto &&[v, w] : edges[u])
            {
                if (power >= w) {
                    auto newd = d + w;
                    if (newd < dist[v][power - w]) {
                        dist[v][power - w] = newd;
                        Q.emplace(newd, v, power - w);
                    }
                }
            }
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
