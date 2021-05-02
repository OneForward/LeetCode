/*
lcci08.14


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
    int countEval(string s, int result) {
        
        auto calc = [](char ch, int x, int y) {
            switch (ch)
            {
            case '&': return x & y;
            case '|': return x | y;
            default: return x ^ y;
            };
        };

        int v[21]{}, N = 0;
        for (auto&& ch: s) {
            if (isdigit(ch)) v[N++] = ch - '0';
        }

        int f[21][21][2]{};
        for (int i = 0; i < N; i++)
        {
            f[i][i][v[i]] = 1;
        }
        
        for (int len = 1; len < N; len++)
        {
            for (int i = 0; i < N-len; i++)
            {
                auto j = i + len;
                for (int k = i; k < j; k++)
                {
                    auto op = s[2 * k + 1];
                    for (auto&& x: {0, 1}) {
                        for (auto&& y: {0, 1}) {
                            auto z = calc(op, x, y);
                            f[i][j][z] += f[i][k][x] * f[k+1][j][y];
                        }
                    }
                }
            }
        }
        return f[0][N-1][result];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countEval("1^0|0|1", 0) << endl;
    cout << sol.countEval("0&0&0&1^1|0", 1) << endl;
    return 0;
}
