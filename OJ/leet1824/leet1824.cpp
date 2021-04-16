/*
leet1824


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


template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
class Solution {
public:
    int minSideJumps(const vector<int>& obstacles) {
        int n = obstacles.size();
        int f[3] = {1, 0, 1}, g[3];
        const int INF = INT_MAX / 2;

        for (int i = 1; i < n; i++)
        {
            COPY(g, f, 3);
            for (int j = 0; j < 3; j++)
            {
                if (j == obstacles[i]-1 or 
                    j == obstacles[i-1]-1) f[j] = INF;
                else f[j] = min(g[j], min(g[(j+1)%3], g[(j+2)%3]) + 1 );
            }
        }
        return min(f[0], min(f[1], f[2]) );
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minSideJumps({0,1,2,3,0}) << endl;
    cout << sol.minSideJumps({0,1,1,3,3,0}) << endl;
    cout << sol.minSideJumps({0,2,1,0,3,0}) << endl;
    return 0;
}
