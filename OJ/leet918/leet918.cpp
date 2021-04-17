/*
leet918


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



class SolutionTLE {
public:
    int maxSubarraySumCircular(const vector<int>& A) {
        // TLE, O(N^2)
        auto B = A; B.insert(B.end(), A.begin(),A.end());
        int N = size(A), prev = 0, sum = 0, ans = INT_MIN;
        // cout << B << endl;
        for (int i = 0; i < 2*N; i++)
        {
            if (sum <= 0) sum = B[i], prev = i;
            else sum += B[i];

            if (i - prev == N) {
                sum -= B[prev]; prev++;
                auto y = sum;
                for (int j = prev; j < i; j++)
                {
                    y -= B[j];
                    if (y >= sum) sum = y, prev = j + 1;
                }
            }
            // cout << sum << ", ";
            ans = max(ans, sum);
        }
        return ans;
    }
};

class SolutionOfficial {
public:
    int maxSubarraySumCircular(const vector<int>& A) {
        // O(N), 两区间和部分亦可以 O(N) 完成
        int N = size(A), sum = 0, ans = INT_MIN;
        vector<int> B(N+1); 
        for (int i = N - 1; i >= 0; i--)
        {
            sum += A[i];
            B[i] = max(B[i+1], sum);
        }
        auto first = 0;
        for (int i = 0; i < N; i++)
        {
            first += A[i]; 
            ans = max(ans, first + B[i+1]);
        }
        
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (sum <= 0) sum = A[i];
            else sum += A[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubarraySumCircular(const vector<int>& A) {
        // O(N)， 两区间和部分转换成最小和问题即可
        int pos = 0, neg = 0, allsum = 0, ans = INT_MIN;
        
        for (auto&& x: A)
        {
            if (pos <= 0) pos = x;
            else pos += x;
            ans = max(ans, pos); allsum += x;
        }

        for (auto&& x: A)
        {
            if (neg >= 0) neg = x;
            else neg += x;
            if (neg != allsum) ans = max(ans, allsum - neg); 
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSubarraySumCircular({0,5,8,-9,9,-7,3,-2}) << endl;
    cout << sol.maxSubarraySumCircular({-2}) << endl;
    cout << sol.maxSubarraySumCircular({1,-2,3,-2}) << endl;
    cout << sol.maxSubarraySumCircular({5,-3,5}) << endl;
    cout << sol.maxSubarraySumCircular({3,-1,2,-1}) << endl;
    cout << sol.maxSubarraySumCircular({3,-2,2,-3}) << endl;
    cout << sol.maxSubarraySumCircular({-2,-3,-1}) << endl;
    return 0;
}
