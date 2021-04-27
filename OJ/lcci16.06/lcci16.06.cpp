/*
lcci16.06


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



#define ALL(A) A.begin(),A.end()
class Solution {
public:
    int smallestDifference(vector<int> A, vector<int> B) {
        sort(ALL(A)); sort(ALL(B));
        int i = 0, j = 0, N = A.size(), M = B.size(); long long ans = LONG_MAX;
        while (i < N and j < M) {
            if (B[j] <= A[i]) ans = min(ans, (long long)A[i] - B[j]), j++;
            else ans = min(ans, (long long)B[j] - A[i]), i++;
        }
        return ans;
    }
}; 

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.smallestDifference({1,5,6,7,8,9,1034,56074,64397,1565,37663,8737,48,56,188,701,9278,64,66,68,838,2638,336,4818,85,4439,90,223,7788}, {62577,4977,5363,122}) << endl;
    return 0;
}
