/*
leet1442


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
    int countTriplets(const vector<int>& A) {
        // Time O(N), Space O(N)
        int N = A.size(), ans = 0, x = 0;
        unordered_map<int, tuple<int,int,int>> S;
        S[0] = {-1, 1, 0};
        for (int i = 0; i < N; i++)
        {
            x ^= A[i];
            if (S.find(x) != S.end()) {
                auto&& [iK, K, fK] = S[x];
                fK += (i - iK) * K - 1; K++; iK = i;
                ans += fK;
            }
            else S[x] = {i, 1, 0};
            // cout << "x = " << x << endl;
            // cout << "S = " << S << endl;
        }
        return ans;
    }
};

class Solution3 {
public:
    int countTriplets(const vector<int>& A) {
        // Time O(N^2) Space O(1)
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; i++)
        {
            int f = 0;
            for (int k = i; k < N; k++)
            {
                f ^= A[k];
                if (f == 0) ans += k - i;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int countTriplets(const vector<int>& A) {
        // O(N^2)
        int N = A.size(), ans = 0;
        unordered_map<int, int> S;
        for (int j = 1; j < N; j++) {
            auto f = S; S.clear(); 
            for (auto&& [x, cnt]: f) {
                S[x ^ A[j-1]] = cnt;
            }
            S[A[j-1]]++;

            int rht = 0;
            for (int k = j; k < N; k++)
            {
                rht ^= A[k];
                if (S.find(rht) != S.end()) ans += S[rht];
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    int countTriplets(const vector<int>& A) {
        int N = A.size(), ans = 0;
        int f[305]{};
        for (int j = 1; j < N; j++) {
            int x = 0;
            for (int i = j-1; i >= 0; i--)
            {
                x ^= A[i];
                f[i] = x;
            }
            x = 0;
            for (int k = j; k < N; k++)
            {
                x ^= A[k];
                for (int i = 0; i < j; i++)
                {
                    if (f[i] == x) ans++;
                }
            }
        }
        return ans;
    }
};




int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countTriplets({2,3,1,6,7}) << endl;
    cout << sol.countTriplets({1,1,1,1,1}) << endl;
    cout << sol.countTriplets({2,3}) << endl;
    cout << sol.countTriplets({1,3,5,7,9}) << endl;
    cout << sol.countTriplets({7,11,12,9,5,2,7,17,22}) << endl;
    return 0;
}
