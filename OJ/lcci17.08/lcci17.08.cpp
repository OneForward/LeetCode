/*
lcci17.08


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
    int bestSeqAtIndex( const vector<int>& height,  const vector<int>& weight) {
        VI H(height.size());
        iota(ALL(H), 0);
        sort(ALL(H), [&](int i, int j) { return ( height[i] == height[j] ? weight[i] > weight[j] : height[i] < height[j]) ; });

        vector<int> v;
        for (auto&& x: H) {
            auto pos = lower_bound(ALL(v), x, [&](int i, int j) {
                return weight[i] < weight[j];
            });
            if (pos == v.end()) v.push_back(x);
            else *pos = x;
        }
        
        return v.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.bestSeqAtIndex({65,70,56,75,60,68}, {100,150,90,190,95,110}) << endl;
    cout << sol.bestSeqAtIndex({6410,4261,939,8469,3780,6773,2255,474,6940,5581}, {825,9198,4361,8999,8365,7399,6664,218,98,5210}) << endl;
    return 0;
}
