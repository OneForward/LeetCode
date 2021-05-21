/*
leet1095


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


class MountainArray {
public:
    vector<int> v;
    MountainArray(const vector<int>& A): v{A} {}
    int get(int i) const { return v[i]; };
    int length() const  { return v.size(); };
};

class Solution {
public:
    int findInMountainArray(int target, const MountainArray &M) {
        int lft = 0, rht = M.length();
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (mid >= 1 and M.get(mid) < M.get(mid - 1)) rht = mid;
            else lft = mid + 1;
        }
        int K = lft;

        lft = 0, rht = K;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            auto midVal  = M.get(mid);
            if (midVal == target) return mid;
            if (midVal > target) rht = mid;
            else lft = mid + 1;
        }
        
        lft = K, rht = M.length();
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            auto midVal  = M.get(mid);
            if (midVal == target) return mid;
            if (midVal < target) rht = mid;
            else lft = mid + 1;
        }
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findInMountainArray(3, MountainArray({1,2,3,4,5,3,1})) << endl;
    cout << sol.findInMountainArray(3, MountainArray({0,5,3,1})) << endl;
    return 0;
}
