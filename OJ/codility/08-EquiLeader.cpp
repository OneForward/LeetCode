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
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return -1;

    int leader = A[0], cnt = 0, n = A.size();
    for (auto&& x: A) {
        if (x == leader) cnt++;
        else if (cnt == 1) leader = x;
        else cnt--;
    }

    cnt = 0; 
    for (auto&& x: A) {
        if (x == leader) cnt++;
    }
    
    if (cnt <= n / 2) return -1;

    int ans = 0, prev = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] == leader) prev++;
        if (prev > (i + 1) / 2 and (cnt - prev) > (n - i - 1) / 2) ans++;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    cout << solution({1,1}) << endl;
    cout << solution({1,2}) << endl;
    cout << solution({4,3,4,4,4,2}) << endl;
    return 0;
}
