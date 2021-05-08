/*
leet1723


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

    int minimumTimeRequired(VI jobs, int k) {
        vector<int> workloads(k);

        function<bool(size_t, int)> f = [&](size_t i, int limit) {
            if (i == jobs.size()) return true;
            int now = jobs[i];
            for (auto&& x: workloads) {
                if (x + now <= limit) {
                    x += now;
                    if (f(i+1, limit)) return true;
                    x -= now;
                }
                
                // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
                // 或者当前工作恰能使该工人的工作量达到了上限
                // 这两种情况下我们无需尝试继续分配工作. 剪枝
                if (x == 0 or x + now == limit) break;
            }
            return false;
        };

        auto ok = [&](int limit) {
            fill(ALL(workloads), 0);
            return f(0, limit);
        };

        sort(ALL(jobs), greater{});
        int lft = jobs[0], rht = reduce(ALL(jobs), 0);
        while (lft < rht) {
            int mid = (lft + rht) >> 1;
            if ( ok(mid) ) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
}; 

int main(int argc, char const *argv[])
{
    Solution sol;  
    cout << sol.minimumTimeRequired({3,2,3}, 3)  << endl;
    cout << sol.minimumTimeRequired({1,2,4,7,8}, 2)  << endl;
    return 0;
}
