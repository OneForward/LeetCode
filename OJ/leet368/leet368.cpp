/*
leet368


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

using ipair=pair<int,int>;
#define ALL(A) A.begin(),A.end()
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> A) {
        int N = A.size();
        ipair f[1005]{};
        sort(ALL(A));

        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < N; i++)
        {
            auto&& [prev, len] = f[i];
            for (int j = i + 1; j < N; j++)
            {
                if (A[j] % A[i] == 0) {
                    auto&& [oldprev, oldlen] = f[j];
                    if (len >= oldlen) f[j] = {i, len + 1};
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            auto&& [prev, len] = f[i];
            if (len > maxLen) maxLen = len, maxIndex = i;
        }
        maxLen++;

        vector<int> ans; ans.reserve(maxLen);
        int i = maxIndex; 
        while (maxLen--) {
            ans.push_back(A[i]);
            i = f[i].first;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.largestDivisibleSubset({1,2,3}) << endl;
    cout << sol.largestDivisibleSubset({1,2,4,8}) << endl;
    cout << sol.largestDivisibleSubset({3,4,16,8}) << endl;
    return 0;
}
