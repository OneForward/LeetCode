/*
lcci05.04


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
    vector<int> findClosedNumbers(int x) {
        // 10 -> 01
        // 1011 -> 0111
        // 110011 -> 101110
        // 10 -> 01 and all tailing 1s to be next to 01...

        // 01 -> 10 
        // 011 -> 101
        // 0110 -> 1001
        
        long long y = 1, rht, lft;
        // find '01'
        while ( y <= INT_MAX and not ( (x & y) == 1 and (x & (y << 1)) == 0 )) y <<= 1;
        rht = x + (y << 1) - y;
        long long z = 1;
        y >>= 1;
        while (y) {
            if (x & y) rht += z, z <<= 1;
            // cout << " y = " << y << endl;
            y >>= 1;
        }
        if (rht > INT_MAX) rht = -1;

        y = 0b10;
        // find '10'
        while ( y <= INT_MAX and not ( (x & y) == 0 and (x & (y << 1)) == 1 )) y <<= 1;
        if (y >= x) lft = -1;
        else {
            lft = x - (y << 1) + y;
            long long z = 1;
            y >>= 1;
            while (true) {
                if (x & z) rht += z, y >>= 1;
                if (z >= x) break;
                // cout << " z = " << z << endl;
                z <<= 1;
            }
        }
        return {(int)rht, (int)lft};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findClosedNumbers(0b10) << endl;
    cout << sol.findClosedNumbers(0b1) << endl;
    cout << sol.findClosedNumbers(0b1010001100010000011) << endl;
    cout << sol.findClosedNumbers(0b100001111) << endl;
    return 0;
}
