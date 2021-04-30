/*
lcci16.25


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <list>
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
// #define SIZE(A) ((int)A.size())
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

using VD=vector<double>;
using VS=vector<string>;


#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

using ipair=pair<int,int>;
class LRUCache {
public:
    list<ipair> L;
    unordered_map<int, list<ipair>::iterator> M;

    size_t SIZE;
    LRUCache(int capacity): SIZE(capacity + 1) { L.push_back({}); }
    
    int get(int key) {
        if (M.find(key) == M.end()) return -1;
        auto p = M[key]; auto [_, val] = *p;
        M[key] = L.insert(L.end(), {key, val});
        L.erase(p);
        return val;
    }
    
    void put(int key, int value) {
        if (M.find(key) == M.end()) {
            if (L.size() == SIZE) {
                auto p = next(L.begin()); auto [key, val] = *p;
                M.erase(key); L.erase(p);
            }
            M[key] = L.insert(L.end(), {key, value});
        }
        else {
            auto p = M[key];
            M[key] = L.insert(L.end(), {key, value});
            L.erase(p);
        }
    }
};


int main(int argc, char const *argv[])
{
    LRUCache cache = LRUCache( 2 /* 缓存容量 */ );

    cache.put(2, 1);
    cache.put(2, 2);
    cout << endl << cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout << endl << cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout << endl << cache.get(1);       // 返回 -1 (未找到)
    cout << endl << cache.get(3);       // 返回  3
    cout << endl << cache.get(4);       // 返回  4

    // LRUCache cache = LRUCache( 2 /* 缓存容量 */ );

    // cache.put(1, 1);
    // cache.put(2, 2);
    // cout << endl << cache.get(1);       // 返回  1
    // cache.put(3, 3);    // 该操作会使得密钥 2 作废
    // cout << endl << cache.get(2);       // 返回 -1 (未找到)
    // cache.put(4, 4);    // 该操作会使得密钥 1 作废
    // cout << endl << cache.get(1);       // 返回 -1 (未找到)
    // cout << endl << cache.get(3);       // 返回  3
    // cout << endl << cache.get(4);       // 返回  4
    
    return 0;
}
