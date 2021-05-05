/*
leet640


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

using Pair = pair<int, int>;
Pair& operator+=(Pair& lft, const Pair& rht) {
    auto&& [k0, b0] = lft;
    auto&& [k, b] = rht;
    k0 += k; b0 += b;
    return lft;
}


class Solution {
public:
    
    Pair parse(string eq) {
        if (eq.back() == 'x') {
            eq.pop_back();
            if (eq.empty()) return {1, 0};
            if (eq.size() == 1) {
                if (eq[0] == '+') return {1, 0};
                if (eq[0] == '-') return {-1, 0};
            }
            return { stoi(eq), 0};
        }
        return {0, (eq.empty() ? 0 : stoi(eq))};
    }
    
    string solveEquation(string eq) {
        int N = eq.size();
        int M = eq.find('=');
        int pos = 0;
        Pair lft, rht;
        for (int i = 0; i <= M; i++)
        {
            if (i == M or eq[i] == '+' or eq[i] == '-') {
                lft += parse(eq.substr(pos, i-pos));
                pos = i;
            }
        }
        
        pos = M + 1;
        for (int i = M+1; i <= N; i++)
        {
            if (i == N or eq[i] == '+' or eq[i] == '-') {
                rht += parse(eq.substr(pos, i-pos));
                pos = i;
            }
        }
        auto&& [k, b] = lft;
        auto&& [kr, br] = rht;
        k -= kr; b -= br;
        if (k == 0 and b == 0) return "Infinite solutions";
        if (k == 0 and b != 0) return "No solution";
        return "x=" + to_string(- b / k);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.solveEquation("-x=-1") << endl;
    cout << sol.solveEquation("x+5-3+x=6+x-2") << endl;
    cout << sol.solveEquation("x=x") << endl;
    cout << sol.solveEquation("2x=x") << endl;
    cout << sol.solveEquation("2x+3x-6x=x+2") << endl;
    cout << sol.solveEquation("x=x+2") << endl;
    return 0;
}
