/*
lcci17.24


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
    vector<int> getMaxMatrix(const vector<vector<int>>& M) {
        int R = M.size(), C = M[0].size(), ans = INT_MIN;
        auto p = make_tuple(0, 0, 0, 0);
        int f[205]{};
        for (int r1 = 0; r1 < R; r1++)
        {
            for (int r2 = r1; r2 < R; r2++)
            {
                for (int c = 0; c < C; c++)
                {
                    f[c] += M[r2][c];
                }
                int x = INT_MIN, sum = 0, c1 = 0;
                auto pc = make_pair(0, 0);
                for (int c = 0; c < C; c++)
                {
                    if (sum < 0) sum = f[c], c1 = c;
                    else sum += f[c];
                    if (sum > x) {
                        x = sum;
                        pc = {c1, c};
                    }
                }
                if (x > ans) {
                    ans = x; 
                    auto&& [c1, c2] = pc;
                    p = {r1, c1, r2, c2};
                }
            }
            
            memset(f, 0, sizeof f);
        }
        auto&& [r1, c1, r2, c2] = p;
        return {r1, c1, r2, c2};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.getMaxMatrix({{-1,0},{0,-1}}) << endl;
    return 0;
}
