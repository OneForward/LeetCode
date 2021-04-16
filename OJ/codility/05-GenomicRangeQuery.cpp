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


vector<int> solution(string S, vector<int> P, vector<int> Q) {
    // 树状数组, range Min
    int N = S.size(), M = P.size();
    VI A(N); 
    auto Map = [](char ch) {
        switch (ch)
        {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        default: return 4;
        }
    };
    
    for (int i = 0; i < N; i++)
        A[i] = Map(S[i]);
    
    VVI f(N, VI(4));
    for (int j = 0; j < A[0] - 1; j++) f[0][j] = -1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < A[i] - 1; j++)
            f[i][j] = f[i-1][j];
        for (int j = A[i]-1; j < 4; j++)
            f[i][j] = i;
    }

    vector<int> ans(M);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (f[Q[i]][j] >= P[i]) { ans[i] = j + 1; goto end;}
        }
        end:;
    }
    
    
    return ans;
}



int main(int argc, char const *argv[])
{
    cout << solution("CAGCCTA", {2, 5, 0}, {4, 5, 6}) << endl;
    
    return 0;
}
