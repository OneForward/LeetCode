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


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> A) {
    int N = A.size(), f = -10005;
    A[0] = A.back() = 0;
    auto lft = A, rht = A;

    for (int i = 0; i < N; i++)
    {
        lft[i] = f = max(f + A[i], A[i]);
    }

    f = -10005;
    for (int i = N-1; i >= 0; i--)
    {
        rht[i] = f = max(f + A[i], A[i]);
    }
    cout << A << endl;
    cout << lft << endl;
    cout << rht << endl;
    int ans = 0;
    for (int i = 1; i < N-1; i++)
    {
        ans = max(ans, max(lft[i-1], 0) + max(0, rht[i+1]));
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    // cout << solution({3, 2, 6, -1, 4, 5, -1, 2}) << endl;
    // cout << solution({1,2,3}) << endl;
    // cout << solution({4,3,4,4,4,2}) << endl;
    cout << solution({0, 10, -5, -2, 0}) << endl;
    return 0;
}
