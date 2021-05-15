/*
lcci16.26


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
    int calculate(string s) {
        enum OP { ADD, SUB, MUL, DIV, OPEN, CLOSE };
        const int Ps[] = {0, 0, 1, 1, 3, 0 };
        auto f = [] (char ch) {
            switch (ch)
            {
            case '+': return ADD;
            case '-': return SUB;
            case '*': return MUL;
            default : return DIV;
            }
        };
        auto calc = [] (OP op, int x, int y) {
            switch (op)
            {
            case ADD: return x + y;
            case SUB: return x - y;
            case MUL: return x * y;
            default : return x / y;
            }
        };
        vector<int> v;
        vector<OP> ops;
        auto process = [&]() {
            auto op = ops.back(); ops.pop_back();
            auto y = v.back(); v.pop_back();
            auto x = v.back(); v.pop_back();
            v.push_back(calc(op, x, y) );
        };
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isspace(s[i])) continue;
            if (isdigit(s[i])) {
                int x = 0;
                while (i < s.size() and isdigit(s[i])) x = x * 10 + (s[i] - '0'), i++;
                v.push_back(x); --i; continue;
            }
            auto op = f(s[i]);
            if (op == ')') {
                while (ops.back() != '(' ) process();
            }
            else {
                while (ops.size() and Ps[ops.back()] >= Ps[op] ) process();
                ops.push_back(op);
            }
        }
        // cout << v << endl;
        while (ops.size()) process();
        return v[0];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.calculate("1 + 2 * 3") << endl;
    cout << sol.calculate(" 3+5 / 2 ") << endl;
    return 0;
}
