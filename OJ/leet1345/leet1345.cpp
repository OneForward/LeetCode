/*
leet1345


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
    int minJumps(const vector<int>& A) {
        if (A.size() == 1) return 0;

        unordered_map<int, int> M;
        int N = A.size(), ans = 0;
        vector<int> f(N, -1);
        bool visited[50005]{};
        for (int i = 0; i < N; i++)
        {
            auto x = A[i];
            if (M.find(x) != M.end()) f[i] = M[x];
            M[x] = i;
        }
        
        queue<int> Q; Q.push(0);
        while (Q.size()) {
            int len = Q.size(); ans++;
            while (len--) {
                auto i = Q.front(); Q.pop();
                if (auto p = i + 1; p <  N and not visited[p]) { if (p == N - 1) return ans; visited[p] = true, Q.push(p);}
                if (auto p = i - 1; p >= 0 and not visited[p]) { if (p == N - 1) return ans; visited[p] = true, Q.push(p);}
                auto x = A[i], p = M[x];
                while (p != -1) {
                    if (p == N - 1) return ans;
                    if (not visited[p]) visited[p] = true, Q.push(p);
                    p = f[p];
                }
                M[x] = -1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minJumps({100,-23,-23,404,100,23,23,23,3,404}) << endl;
    cout << sol.minJumps({7,6,9,6,9,6,9,7}) << endl;
    cout << sol.minJumps({7}) << endl;
    cout << sol.minJumps({6,1,9}) << endl;
    cout << sol.minJumps({11,22,7,7,7,7,7,7,7,22,13}) << endl;
    return 0;
}
