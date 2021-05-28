/*
leet1707


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

struct TrieNode
{
    int val{};
    TrieNode* next[2]{};
};

const int L = 30;
struct Trie
{
    TrieNode root;
    void insert(int x) {
        int y = 1<<L;
        auto p = &root;
        while (y) {
            auto v = ((y & x)) ? 1 : 0;
            if (not p->next[v]) p->next[v] = new TrieNode{};
            p = p->next[v]; y >>= 1;
        }
        p->val = x;
    }

    int query(int x) {
        int y = 1<<L;
        auto p = &root;
        if (not p->next[0] and not p->next[1]) return -1;
        while (y) {
            auto v = ((y & x)) ? 0 : 1;
            if (not p->next[v]) v = 1 - v;
            p = p->next[v]; y >>= 1;
        }
        return p->val ^ x;
    }
};




class Solution {
public:
    vector<int> maximizeXor(vector<int> A, vector<vector<int>> Q) {
        sort(ALL(A));
        VI I(Q.size()); 
        iota(ALL(I), 0);
        auto cmp = [&](int i, int j) {
            return Q[i][1] < Q[j][1];
        };
        sort(ALL(I), cmp);
        
        auto p = A.begin();
        VI ans(Q.size());
        Trie trie;
        for (auto&& i: I) {
            auto&& q = Q[i];
            auto x = q[0], M = q[1];
            while (p != A.end() and *p <= M) {
                trie.insert(*p);
                ++p;
            }
            ans[i] = trie.query(x);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maximizeXor({0,1,2,3,4}, {{3,1}, {1,3}, {5,6}}) << endl;
    cout << sol.maximizeXor({5,2,4,6,6,3}, {{12,4}, {8,1}, {6,3}}) << endl;
    return 0;
}
