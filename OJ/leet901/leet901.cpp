/*
leet901


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
// #include "../utils/LeetCpp.utils.hpp"

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



class StockSpanner {
public:
    struct Pair
    {
        int price, day;
    };
    
    stack<Pair> S;
    int today = 0;

    StockSpanner() { }
    
    int next(int price) {
        while (S.size() and S.top().price <= price) S.pop();
        auto ans = ++today;
        if (S.size()) ans -= S.top().day;
        S.push({price, today});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main(int argc, char const *argv[])
{
    auto S = StockSpanner(); // 然后：
    cout << endl << S.next(100); // 被调用并返回 1，
    cout << endl << S.next(80); // 被调用并返回 1，
    cout << endl << S.next(60); // 被调用并返回 1，
    cout << endl << S.next(70); // 被调用并返回 2，
    cout << endl << S.next(60); // 被调用并返回 1，
    cout << endl << S.next(75); // 被调用并返回 4，
    cout << endl << S.next(85); // 被调用并返回 6。
 
    
    return 0;
}
