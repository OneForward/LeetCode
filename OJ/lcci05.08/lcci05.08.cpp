/*
lcci05.08


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
    vector<int> drawLine(int N, int w, int x1, int x2, int y) {
        vector<int> ans(N);
        int W = w / 32;
        int f1 = y * W + x1 / 32, f2 = y * W + x2 / 32;
        for (int i = f1; i < f2; i++) ans[i] = -1;
        int mask1 = ans[f1] =  ( (1L << (32 - x1 % 32)) - 1 );
        int mask2 = ans[f2] = ~( (1L << (31 - x2 % 32)) - 1 ) & -1;
        if (f1 == f2) ans[f1] = mask1 & mask2;
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << (1 << 0) << endl;
    // cout << sol.drawLine(1,32,30,31,0) << endl;
    // cout << sol.drawLine(3, 96, 0, 95, 0) << endl;
    cout << sol.drawLine(15, 96, 81, 95, 1) << endl;
    return 0;
}
