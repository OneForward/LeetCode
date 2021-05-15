/*
lcci16.16


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
    vector<int> subSort(const vector<int>& A) {
        if (A.empty()) return {-1, -1};

        int lft = 0, N = A.size(), rht = N - 1;
        for (; lft < N-1; ++lft) {
            if ( A[lft] > A[lft + 1]) break;
        }
        for (int i = lft + 1; i < N; i++)
        {
            if (A[i] < A[lft]) {
                auto pos = upper_bound(A.begin(), A.begin() + lft, A[i]) - A.begin();
                lft = pos - 1; 
                if (lft == -1) break;
            }
        }
        
        for (; rht >= 1; --rht) {
            if ( A[rht - 1] > A[rht]) break;
        }
        for (int i = rht - 1; i >= 0; --i)
        {
            if (A[i] > A[rht]) {
                rht = lower_bound(A.begin() + rht, A.end(), A[i]) - A.begin();
                if (rht == N) { break;}
            }
        }
        // printf("lft, rht = %d, %d\n", lft, rht);
        if (lft >= rht) return {-1, -1};
        return {lft + 1, rht - 1};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.subSort({1,2,4,7,10,11,7,12,6,7,16,18,19}) << endl;
    cout << sol.subSort({1}) << endl;
    cout << sol.subSort({1,3,9,7,5}) << endl;
    cout << sol.subSort({3,1}) << endl;
    return 0;
}
