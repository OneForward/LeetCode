/*
lcp23


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
    int f[5005], g[5005], N;
    
    bool ok(const vector<int>& A, int k) {
        iota(f, f + N, 1);

        for (int start = 0; start < N; start+=k)
        {
            int gi = 0;
            for (int i = 1; start + i < N; i += 2)
                g[gi++] = f[start + i];
            for (int i = 0; start + i < N; i += 2)
                g[gi++] = f[start + i];
            for (int i = 0; start + i < N; i++) {
                f[start + i] = g[i];
                if (i < k and f[start + i] != A[start + i] ) return false;
            }
        }
        return true;
    }

    bool isMagic(const vector<int>& A) {
        // 模拟法
        N = A.size();
        int k = 0, v = 2;
        while (k < N and A[k++] == v) v += 2, v = (v <= N ? v : 1);
        return k > 1 and ok(A, k - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << boolalpha;   
    cout << sol.isMagic({2,4,3,1,5}) << endl;
    cout << sol.isMagic({2,4,1,3,5}) << endl;
    cout << sol.isMagic({2,4,6,8,10,12,14,16,1,3,5,7,9,13,11,15}) << endl;
    cout << sol.isMagic({5,4,3,2,1}) << endl;
    return 0;
}
