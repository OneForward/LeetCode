/*
leet274


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



class Solution {
public:
    int hIndex(vector<int> citations) {
        // 计数排序，将超出 N 的数设置为 N ，O(N) in Time and Extra Space
        int n = citations.size();
        vector<int> Count(n+1), f(n);
        for (auto&& x: citations) {
            Count[min(n, x)]++;
        }
        for (int i = 1; i <= n; i++)
        {
            Count[i] += Count[i-1];
        }

        for (auto&& x: citations) {
            f[--Count[min(n, x)]] = x;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (f[n-1-i] == i + 1) return i + 1;
            if (f[n-1-i] < i + 1) return i;
        }

        return n;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.hIndex({3,0,6,1,5}) << endl;
    cout << sol.hIndex({1,3,1}) << endl;
    cout << sol.hIndex({6,5,5,5}) << endl;
    cout << sol.hIndex({6,5,4,1}) << endl;
    cout << sol.hIndex({6,5,4}) << endl;
    cout << sol.hIndex({6,}) << endl;
    cout << sol.hIndex({1,}) << endl;
    cout << sol.hIndex({0,}) << endl;
    cout << sol.hIndex({0,0,0}) << endl;
    cout << sol.hIndex({}) << endl;
    return 0;
}
