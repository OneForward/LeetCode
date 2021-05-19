/*
leet632


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

// TODO 滑动窗口

using Pair = pair<int, size_t>;
class Solution {
public:
    vector<int> smallestRange(const vector<vector<int>>& A) {
        // 二叉堆

        priority_queue Q(greater<Pair>{}, vector<Pair>{});

        size_t I[3505]{}, rht = 0;         
        for (size_t i = 0; i < A.size(); i++) {
            Q.push({A[i][0], i});
            if (A[i][0] > A[rht][0]) rht = i;
        }

        int L = -100005, R = 100005, frht = A[rht][0];
        while (true) {
            auto [flft, lft] = Q.top(); Q.pop();
            if (frht - flft < R - L or (frht - flft == R - L and flft < L)) L = flft, R = frht;
            
            I[lft]++; 
            if (I[lft] < A[lft].size()) Q.push({A[lft][I[lft]], lft});
            else break;
            if (A[lft][I[lft]] > frht) rht = lft, frht = A[rht][I[rht]];
        }
        return {L, R};
    }
};

class Solution2 {
public:
    vector<int> smallestRange(const vector<vector<int>>& A) {
        // 二叉堆

        size_t I[3505]{}; 
        auto f = [&](size_t i) { return A[i][I[i]]; };
        auto cmp = [&] (size_t i, size_t j) {
            return f(i) > f(j);
        };
        priority_queue Q(cmp, vector<size_t>{});

        size_t rht = 0;
        for (size_t i = 0; i < A.size(); i++) {
            Q.push(i);
            if (f(i) > f(rht)) rht = i;
        }

        int L = -100005, R = 100005;
        while (true) {
            auto lft = Q.top(); Q.pop();
            // cout << "lft = " << lft << ", rht = " << rht << endl;
            int flft = f(lft), frht = f(rht);
            if (frht - flft < R - L or (frht - flft == R - L and flft < L)) L = flft, R = frht;
            // cout << "removing " << *S.begin() << endl;
            I[lft]++; 
            if (I[lft] < A[lft].size()) Q.push(lft);
            else break;
            if ((f(lft)) > frht) rht = lft;
        }
        return {L, R};
    }
};




class Solution1 {
public:
    vector<int> smallestRange(const vector<vector<int>>& A) {
        // 二叉树
        set<pair<int,int>> S;
        size_t I[3505]{}; int i = 0;
        for (auto&& v: A) S.insert({v[0], i++});
        int L = -100005, R = 100005;
        while (true) {
            int lft = S.begin()->first, rht = S.rbegin()->first;
            // cout << "lft = " << lft << ", rht = " << rht << endl;
            if (rht - lft < R - L or (rht - lft == R - L and lft < L)) L = lft, R = rht;
            // cout << "removing " << *S.begin() << endl;
            int i = S.begin()->second; S.erase(S.begin());
            I[i]++; 
            if (I[i] < A[i].size()) S.insert({A[i][I[i]], i});
            else break;
        }
        return {L, R};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.smallestRange({{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}}) << endl;
    cout << sol.smallestRange({{1,2,3},{1,2,3},{1,2,3}}) << endl;
    cout << sol.smallestRange({{10,10},{11,11}}) << endl;
    return 0;
}
