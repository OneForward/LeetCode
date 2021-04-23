/*
leet491


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


const long long MOD = 1e9 + 7;
class Solution {
public:
    vector<vector<int>> findSubsequences(const vector<int>& A) {
        // 难点： 去重复
        int N = A.size();
        unordered_set<int> S;
        auto hash = [](const vector<int>& v, int x) {
            long long f = x + 101;
            for (auto&& y: v) {
                f = f * 233 + y + 101;
                f %= MOD;
            }
            return f;
        };

        vector<vector<int>> ans;
        for (int i = 1; i < N; i++)
        {
            int len = ans.size();
            for (int j = 0; j < len; j++)
            {
                if (ans[j].back() <= A[i]) {
                    auto h = hash(ans[j], A[i]);
                    if (S.find(h) != S.end()) continue;
                    auto v = ans[j]; v.push_back(A[i]); S.insert(h);
                    ans.push_back( v );
                }
            }
            
            for (int j = 0; j < i; j++)
            {
                if (A[j] <= A[i]) {
                    auto h = hash({A[j]}, A[i]);
                    if (S.find(h) != S.end()) continue;
                    ans.push_back({A[j], A[i]}); S.insert(h);
                }
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findSubsequences({4,6,7,7}) << endl;
    cout << sol.findSubsequences({-1,0,0,0}) << endl;
    return 0;
}
