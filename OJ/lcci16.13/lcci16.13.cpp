/*
lcci16.13


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
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;


#define ALL(A) A.begin(),A.end()
using ipair=pair<double,double>;
using VP=vector<ipair>;
class Solution {
public:
    vector<double> cutSquares(const vector<int>& S1, const vector<int>& S2) {
        auto x1 = S1[0], y1 = S1[1], L1 = S1[2];
        auto x2 = S2[0], y2 = S2[1], L2 = S2[2];
        auto cx1 = x1 + L1 / 2., cy1 = y1 + L1 / 2.;
        auto cx2 = x2 + L2 / 2., cy2 = y2 + L2 / 2.;

        double rx1, ry1, rx2, ry2; VP v;
        if (abs(cx1 - cx2) > 1e-8 and abs(cy1 - cy2) > 1e-8) {
            auto k = (cy1 - cy2) / (cx1 - cx2);
            auto b = cy1 - k * cx1;
            
            if (auto y = k * x1 + b; y1 <= y and y <= y1 + L1 ) rx1 = x1, ry1 = y;
            else rx1 = ( y1 - b ) / k, ry1 = y1;

            if (auto y = k * x2 + b; y2 <= y and y <= y2 + L2 ) rx2 = x2, ry2 = y;
            else rx2 = ( y2 - b ) / k, ry2 = y2;

            v = {{rx1, ry1}, {2 * cx1 - rx1, 2 * cy1 - ry1}, {rx2, ry2}, {2 * cx2 - rx2, 2 * cy2 - ry2}, };
        }
        else if (abs(cx1 - cx2) > 1e-8) {
            v = {{x1, cy1}, {x1 + L1, cy1}, {x2, cy1}, {x2 + L2 , cy1}};
        }
        else {
            v = {{cx1, y1}, {cx1, y1 + L1}, {cx2, y2}, {cx2, y2 + L2}};
        }
        
        sort(ALL(v));
        auto&& [a, b] = v[0];
        auto&& [c, d] = v[3];
        return {a, b, c, d};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.cutSquares({-1,-1,2}, {0,-1,2}) << endl;
    // cout << sol.cutSquares({-1,1,3}, {0,0,5}) << endl;
    cout << sol.cutSquares({68, 130, 64}, {-230, 194, 7}) << endl;
    return 0;
}
