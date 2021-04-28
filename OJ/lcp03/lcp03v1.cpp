/*
lcp03


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

// using VVP=vector<VP>;
// using VI=vector<int>;
// using VD=vector<double>;
// using VVI=vector<VI>;
// using VS=vector<string>;

using ipair=pair<int,int>;
using VP=vector<ipair>;
class Solution {
public:
    bool robot(string command, const vector<vector<int>>& obstacles, int x, int y) {
        // 稍显繁琐，细节颇多
        VP v = {{0, 0}}; auto pos = v.back();
        for (auto&& ch: command) {
            if (ch == 'R') pos.first++, v.push_back(pos);
            else pos.second++, v.push_back(pos);
        }

        const auto [Tx, Ty] = v.back(); v.pop_back();
        const int N = v.size();
        auto check = [&, Tx=Tx, Ty=Ty](int x, int y) -> ipair {
            int ans = INT_MAX, idx = N;
            for (int i = 0; i < N; ++i) {
                auto&& [px, py] = v[i];
                if (Tx == 0 and Ty == 0) {
                    if (x == px and y == py) return {0, i};
                }
                else if (Tx == 0 and Ty) {
                    if (x == px and (y - py) % Ty == 0) {
                        if (ans > (y - py) / Ty) ans = (y - py) / Ty, idx = i;
                    }
                }
                else if (Tx and Ty == 0) {
                    if ((x - px) % Tx == 0 and y == py) {
                        if (ans > (x - px) / Tx) ans = (x - px) / Tx, idx = i;
                    }
                }
                else {
                    if ((x - px) % Tx == 0 and (y - py) % Ty == 0 and (x - px) / Tx == (y - py) / Ty )  {
                        if (ans > (x - px) / Tx) ans = (x - px) / Tx, idx = i;
                    }
                }
            }
            return {ans, idx};
        };
        
        // cout << v << endl;

        auto dest = check(x, y);
        if (dest.first == INT_MAX) return false;

        for (auto&& bad: obstacles) {
            if (check(bad[0], bad[1]) <= dest) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    // cout << sol.robot("URR", {}, 3, 2) << endl;
    // cout << sol.robot("URR", {}, 4, 2) << endl;
    // cout << sol.robot("URR", {{2,2}}, 3, 2) << endl;
    cout << sol.robot("URR", {{4,2}}, 3, 2) << endl;
    return 0;
}
