/*
leet407


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



class Solution {
public:
    int trapRainWater(const vector<vector<int>>& H) {
        // 贪心, 从最外到最内，每次从最低处试探 
        using Tuple = tuple<int, int, int>;
        priority_queue Q(greater<Tuple>{}, vector<Tuple>{});
        int M = H.size(), N = H[0].size(), ans = 0;
        bool visited[111][111]{};
        for (int i: {0, M-1}) {
            for (int j = 0; j < N; j++)
            {
                Q.emplace(H[i][j], i, j); 
                visited[i][j] = true;
            }
        }
        for (int j :{0, N-1}) {
            for (int i = 0; i < M; i++)
            {
                Q.emplace(H[i][j], i, j); 
                visited[i][j] = true;
            }
        }

        const int DIR[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (Q.size()) {
            auto [h, x, y] = Q.top(); Q.pop();
            for (auto&& [dx, dy]: DIR) {
                auto r = x + dx, c = y + dy;
                if (r < 0 or r >= M or c < 0 or c >= N or visited[r][c]) continue;
                if (H[r][c] < h) ans += h - H[r][c];
                visited[r][c] = true;
                Q.emplace(max(h, H[r][c]), r, c);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.trapRainWater({
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1},
    }) << endl;
    cout << sol.trapRainWater({
        {12,13,1,12},
        {13,4,13,12},
        {13,8,10,12},
        {12,13,12,12},
        {13,13,13,13},
    }) << endl;
    return 0;
}
