/*
leet1738


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
#include "../utils/LeetCpp.utils.hpp"

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

template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VD=vector<double>;
using VS=vector<string>;
using VP=vector<ipair>;
using VVP=vector<VP>;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

class Solution {
public:
    int kthLargestValue(const vector<vector<int>>& M, int k) {
        auto R = M.size(), C = M[0].size();
        int f[1005][1005]{};
        int g[1000000], idx = 0;
        for (size_t r = 0; r < R; r++)
        {
            for (size_t c = 0; c < C; c++)
            {
                g[idx++] = f[r+1][c+1] = f[r][c] ^ f[r+1][c] ^ f[r][c+1] ^ M[r][c];
            }
        }
        nth_element(g, g + k-1, g + R * C, greater<int>{});
        return g[k-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthLargestValue({{5,2},{1,6}}, 1) << endl;
    cout << sol.kthLargestValue({{5,2},{1,6}}, 2) << endl;
    cout << sol.kthLargestValue({{5,2},{1,6}}, 3) << endl;
    cout << sol.kthLargestValue({{5,2},{1,6}}, 4) << endl;
    return 0;
}
