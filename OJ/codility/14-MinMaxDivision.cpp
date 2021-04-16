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


int solution(int K, int M, vector<int> A) {
    // O(M log N)
    int sum = accumulate(ALL(A), 0);
    int maxA = *max_element(ALL(A));
    int lft = max(maxA, sum / K);

    int rht = lft + maxA + 1; // 上界可能不易理解，其实使用 rht = sum 也 OK ，复杂度至多差一个常数2
    while (lft < rht) {
        auto mid = (lft + rht) / 2;
        auto currBlockSum = 0, block = 1;
        for (auto&& x: A) {
            currBlockSum += x;

            if (currBlockSum <= mid) continue;

            ++block;
            currBlockSum = x;
            if (block > K) break;
        }

        if (block <= K) rht = mid;
        else lft = mid + 1;
    }

    return lft;
}


int main(int argc, char const *argv[])
{
    cout << solution  (3, 5, {2, 1, 5, 1, 2, 2, 2} ) << endl;
    
    return 0;
}
