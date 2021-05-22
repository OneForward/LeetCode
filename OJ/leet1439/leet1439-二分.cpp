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

class Solution {
public:
    int kthSmallest(const vector<vector<int>>& M, int K) {
        int R = M.size(), C = M[0].size(), lft = 0, rht = 1;
        for (auto&& row: M) lft += row.front(), rht += row.back();
        int f0 = lft;
        function<int(int, int, int)> f = [&](int x, int r, int sum) {
            if (r == R or sum > x) return 0;
            auto cnt = f(x, r+1, sum), y0 = M[r][0];
            if (cnt > K) return cnt;
            for (int c = 1; c < C; c++)
            {
                auto y = M[r][c];
                if (sum + y - y0 <= x) cnt += f(x, r + 1, sum + y - y0) + 1;
                else break;
                if (cnt > K) return cnt;
            }
            return cnt;
        };


        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (f(mid, 0, f0) >= K - 1) rht = mid; 
            else lft = mid + 1;
        }
        return lft;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.kthSmallest({{1,10,10},{1,4,5},{2,3,6}}, 7) << endl;
    cout << sol.kthSmallest({{1,3,11}, {2,4,6}}, 9) << endl;
    return 0;
}
