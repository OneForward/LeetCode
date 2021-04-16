/*
codility


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


int solution(vector<int> A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<long long> f(n), g(n);
    for (long long i = 0; i < n; i++)
    {
        f[i] = - i - A[i];
        g[i] = i - A[i];
    }

    sort(ALL(f));
    sort(ALL(g));

    auto cnt = - (long long) n * (n + 1);
    for (long long j = 0; j < n; j++)
    {
        cnt += upper_bound(ALL(f), A[j] - j) - f.begin();
        cnt += upper_bound(ALL(g), A[j] + j) - g.begin();
        if (cnt > 20'000'000) return -1;
    }
    return cnt / 2;
}



int main(int argc, char const *argv[])
{
    cout << solution  ({1, INT_MAX, 0} ) << endl;
    cout << solution  ({1, 5, 2, 1, 4, 0} ) << endl;
    cout << solution  (vector<int>(100000) ) << endl;
    
    return 0;
}