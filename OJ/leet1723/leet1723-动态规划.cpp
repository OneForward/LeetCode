/*
leet1723


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
    int minimumTimeRequired(const vector<int>& jobs, int K) {
        const int MAX = 12;
        int A[1<<MAX]{};
        int f[1<<MAX]{};
        int g[1<<MAX]{};
        memset(f, 0xf, sizeof f);

        int N = jobs.size();
        for (int i = 0; i < N; i++)
        {
            A[1<<i] = jobs[i];
        }
        
        for (int x = 0; x < 1<<N; x++)
        {
            A[x] = A[x & (x-1)] + A[x & -x];
        }
        
        memcpy(g, A, sizeof g);
        for (int k = 1; k < K; k++)
        {
            for (int x = 0; x < 1<<N; x++)
            {
                for (int y = x; y; y = (y - 1) & x)
                {
                    if ((x | y) == x) {
                        // NOTE: y is subset of x , iterate over subsets of x
                        f[x] = min(f[x], max(A[y], g[x ^ y]));
                    }
                }
            }
            memcpy(g, f, sizeof g);
            memset(f, 0x7f, sizeof f);
        }
        return g[(1<<N) - 1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;  
    cout << sol.minimumTimeRequired({3,2,3}, 3)  << endl;
    cout << sol.minimumTimeRequired({1,2,4,7,8}, 2)  << endl;
    return 0;
}
