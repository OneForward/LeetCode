/*
leet1306


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
    bool canReach(const vector<int>& A, int start) {
        bool f[50005]{}; int N = A.size();
        f[start] = true;
        queue<int> Q; Q.push(start);
        if (A[start] == 0) return true;
        while (Q.size()) {
            int len = Q.size();
            while (len--) {
                auto p = Q.front(); Q.pop();
                if (auto q = p + A[p]; q <  N and not f[q]) { if (A[q] == 0) return true; f[q] = true, Q.push(q);}
                if (auto q = p - A[p]; q >= 0 and not f[q]) { if (A[q] == 0) return true; f[q] = true, Q.push(q);}
            }
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.canReach({4,2,3,0,3,1,2}, 5) << endl;
    cout << sol.canReach({4,2,3,0,3,1,2}, 0) << endl;
    cout << sol.canReach({3,0,2,1,2}, 2) << endl;
    return 0;
}
