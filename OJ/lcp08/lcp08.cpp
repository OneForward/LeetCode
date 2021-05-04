/*
lcp08


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
    vector<int> getTriggerTime(const vector<vector<int>>& increase, const vector<vector<int>>& requirements) {
        int fx[10005]{}, fy[10005]{}, fz[10005]{};
        int T = 1;
        for (auto&& v: increase)
        {
            auto x = v[0], y = v[1], z = v[2];
            fx[T] = fx[T - 1] + x;
            fy[T] = fy[T - 1] + y;
            fz[T] = fz[T - 1] + z; T++;
        }

        vector<int> ans; ans.reserve(requirements.size());
        for (auto&& v: requirements) {
            auto x = v[0], y = v[1], z = v[2];
            auto px = lower_bound(fx, fx + T, x) - fx ;
            auto py = lower_bound(fy, fy + T, y) - fy ;
            auto pz = lower_bound(fz, fz + T, z) - fz ;
            int pos = max({px, py, pz});
            ans.push_back( ( pos == T ? -1 : pos) );
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.getTriggerTime({{2,8,4},{2,5,0},{10,9,8}},   {{2,11,3},{15,10,7},{9,17,12},{8,1,14} }) << endl;
    cout << sol.getTriggerTime({{0,4,5},{4,8,8},{8,6,1},{10,10,0}},   {{12,11,16},{20,2,6},{9,2,6},{10,18,3},{8,14,9} }) << endl;
    cout << sol.getTriggerTime({{1,1,1}},   {{0,0,0}}) << endl;
    return 0;
}
