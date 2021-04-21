/*
leet981


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

template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;



#define ALL(A) A.begin(),A.end()
using Pair=pair<int, string>;
using VP=vector<Pair>;
class TimeMap {
public:
    unordered_map<string, VP> M;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        M[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (M.find(key) == M.end()) return {};
        auto&& v = M[key];
        auto cmp = [&](const Pair& p1, const Pair& p2) {
            return p1.first < p2.first;
        };
        auto pos = upper_bound(ALL(v), Pair{timestamp, {}}, cmp) - v.begin();
        if (pos == 0) return {};
        return v[pos-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(int argc, char const *argv[])
{
    TimeMap kv; 
    kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
    cout << endl << kv.get("foo", 1);  // 输出 "bar"   
    cout << endl << kv.get("foo", 3); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
    kv.set("foo", "bar2", 4);
    cout << endl << kv.get("foo", 4); // 输出 "bar2"   
    cout << endl << kv.get("foo", 5); // 输出 "bar2"   

    
    return 0;
}
