/*
leet1439


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

using Pair=pair<int, int>;
class Solution {
public:
    int kthSmallest(const vector<vector<int>>& M, int K) {
        int R = M.size(), C = M[0].size();
        int f[201*41][41]{}, top = 0, sum = 0;
        long long hash[201*41]{};
        long long P[45]{1};
        const long long MOD = 1e9 + 7;
        unordered_set<long long> S;
        
        priority_queue Q(greater<Pair>{}, vector<Pair>{});
        
        for (int r = 0; r < R; r++) {
            P[r+1] = P[r] * 41 % MOD;
            sum += M[r][0];
        }

        Q.emplace(sum, 0); top++;

        while (--K) {
            auto [sum, r0] = Q.top(); Q.pop();
            auto h = hash[r0];
            // printf("sum = %d, r0 = %d\n", sum, r0);
            
            // for (int r = 0; r < R; r++) cout << f[r0][r] << ", ";cout << endl;
            // for (int r = 0; r < R; r++) cout << M[r][f[r0][r]] << ", ";cout << endl;
            

            for (int r = 0; r < R; r++)
            {
                if (f[r0][r] == C - 1) continue;
                auto newh = (h +  P[r]) % MOD;
                if (S.find(newh) != S.end()) continue;

                memcpy(f+top, f+r0, sizeof f[0]);
                auto& c = f[top][r]; c++; 
                Q.emplace(sum + M[r][c] - M[r][c-1], top);
                S.insert(newh); hash[top] = newh; top++;
            }
        }
        // cout << S << endl;
        
        return Q.top().first;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthSmallest({{1,10,10},{1,4,5},{2,3,6}}, 7) << endl;
    cout << sol.kthSmallest({{1,3,11}, {2,4,6}}, 9) << endl;
    return 0;
}
