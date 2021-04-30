/*
lcp36


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



class Solution {
public:
    int maxGroupNumber(const vector<int>& tiles) {
        map<int, int> M;
        for (auto&& x: tiles) M[x]++;

        int f[5][5], g[5][5];
        auto reset = [](int f[5][5], int start) {
            memset(f, 0xff, 25 * sizeof (int));
            f[0][0] = start;
        };
        
        reset(f, 0);
        // f[x][y]: 预留 x 张 [card-2]  和 y 张 [card-1] 的前提下
        // [card] 之前的牌能组成的牌组数

        int prev = 0;
        for (auto&& [card, cnt]: M) {
            if (prev != card - 1) {
                reset(f, f[0][0]); // 只保留 f[0][0], f[i][j] < 0 表示没有预留这样数量的牌
            }

            reset(g, -1);
            for (int cnt2 = 0; cnt2 < 5; cnt2++)
            {
                for (int cnt1 = 0; cnt1 < 5; cnt1++)
                {
                    if (f[cnt2][cnt1] < 0) continue;
                    
                    // 枚举顺子
                    for (int shunzi = 0; shunzi <= min({cnt2, cnt1, cnt}); shunzi++)
                    {
                        int new2 = cnt1 - shunzi;
                        for (int new1 = 0; new1 <= min(4, cnt-shunzi); new1++)
                        {
                            int score = f[cnt2][cnt1] + shunzi + (cnt - shunzi - new1) / 3;
                            g[new2][new1] = max(g[new2][new1], score);
                        }
                    }
                }
            }

            memcpy(f, g, sizeof f);
            prev = card;
        }

        int ans = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                ans = max(ans, f[i][j]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxGroupNumber({2,2,2,3,4}) << endl;
    cout << sol.maxGroupNumber({2,2,2,3,4,1,3}) << endl;
    return 0;
}
