/*
leet1787


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
    int minChanges(const vector<int>& A, int K) {
        int N = A.size(), R = 0;
        const int M = 1<<10;
        int f[M]{}, g[M]{}, C[M]{};
        
        for (int i = 0; i < N; i+=K) C[A[i]]++, R++;
        for (int x = 0; x < M; x++) f[x] = R - C[x];
        
        for (int k = 1; k < K; k++)
        {
            memset(C, 0, sizeof C); R = 0;
            auto fmin = *min_element(f, f + M);
            for (int i = k; i < N; i+=K) C[A[i]]++, R++;
            for (int x = 0; x < M; x++) {
                g[x] = fmin + R;
                for (int i = k; i < N; i+=K)
                {
                    auto y = A[i];
                    g[x] = min(g[x], f[y ^ x] + R - C[y]);
                }
            }
            memcpy(f, g, sizeof g);
        }
        
        return f[0];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minChanges({1,2,0,3,0}, 1) << endl;
    cout << sol.minChanges({3,4,5,2,1,7,3,4,7}, 3) << endl;
    cout << sol.minChanges({1,2,4,1,2,5,1,2,6}, 3) << endl;
    return 0;
}
