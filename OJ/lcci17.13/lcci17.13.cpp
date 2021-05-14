/*
lcci17.13


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

const int MOD = 1e9 + 7;

int hash_string(const string& s) {
    auto x = 0LL; auto N = s.size();
    for (int i = N - 1; i >= 0; i--)
        x = x * 133 + s[i], x %= MOD;
    return x;
}

class Solution {
public:
    int respace(const vector<string>& dictionary, string s) {
        int f[1005]{}, N = s.size(), ans = 0;
        // unordered_set S(ALL(dictionary));
        unordered_set<int> S;
        for (auto&& word: dictionary) S.insert(hash_string(word));
        for (int i = 0; i < N; i++)
        {
            f[i + 1] = f[i];
            auto x = 0LL;
            for (int j = i; j >= 0; j--)
            {
                // s[j..i]
                x = x * 133 + s[j], x %= MOD;
                if (S.find(x) != S.end()) {
                    // f[i + 1] = max(f[i + 1],  f[j] + 1);
                    f[i + 1] = max(f[i + 1] ,  f[j] + i - j + 1 );
                }
            }
            ans = max(ans, f[i + 1]);
        }
        // for (int i = 0; i < N; i++) cout << f[i] << ", "; cout << endl;
        return N - ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.respace({"looked","just","like","her","brother"}, "jesslookedjustliketimherbrother") << endl;
    return 0;
}
