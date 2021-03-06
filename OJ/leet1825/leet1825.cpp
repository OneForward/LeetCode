/*
leet1825


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



class MKAverage {
public:
    multiset<int> S;
    queue<int> Q;
    int M, K;
    long long sum = 0;
    decltype(S.begin()) lft, rht;

    MKAverage(int m, int k): M{m}, K{k} {}
    
    void addElement(int newx) {
        Q.push(newx); S.insert(newx);
        if (Q.size() == M) {
            int i = 0; auto p = S.begin();
            for ( i = 0; i < K; i++) ++p;
            lft = p; 
            for ( ; i < M-K; ++i) sum += *p, ++p;
            rht = prev(p);
        }


        if (Q.size() > M) {
            if (newx < *lft) lft--, sum += *lft;
            else if (newx >= *rht) rht++, sum += *rht;
            else sum += newx;

            int x = Q.front(); Q.pop();
            auto p = S.lower_bound(x);
            if (x <= *lft) sum -= *lft, lft++;
            else if (x > *rht or p == rht) sum -= *rht, rht--; // ??????????????????????????????????????????????????? p == rht ?????????
            else sum -= x;
            S.erase(p); 
        }
    }
    
    int calculateMKAverage() {
        if (Q.size() < M) return -1;
        return sum / (M - K - K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

int main(int argc, char const *argv[])
{
    // MKAverage obj =  MKAverage(3, 1); 
    // obj.addElement(3);        // ??????????????? [3]
    // obj.addElement(1);        // ??????????????? [3,1]
    // cout << endl << obj.calculateMKAverage(); // ?????? -1 ????????? m = 3 ???????????????????????? 2 ?????????
    // obj.addElement(10);       // ??????????????? [3,1,10]
    // cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [3,1,10]
    //                         // ??????????????????????????? 1 ???????????????????????? [3]
    //                         // [3] ?????????????????? 3/1 = 3 ???????????? 3
    // obj.addElement(5);        // ??????????????? [3,1,10,5]
    // obj.addElement(5);        // ??????????????? [3,1,10,5,5]
    // obj.addElement(5);        // ??????????????? [3,1,10,5,5,5]
    // cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [5,5,5]
    //                         // ??????????????????????????? 1 ???????????????????????? [5]
    //                         // [5] ?????????????????? 5/1 = 5 
    
    MKAverage obj =  MKAverage(3, 1); 
    obj.addElement(58916);        // ??????????????? [3]
    obj.addElement(61899);        // ??????????????? [3,1]
    cout << endl << obj.calculateMKAverage(); // ?????? -1 ????????? m = 3 ???????????????????????? 2 ?????????
    obj.addElement(85406);       // ??????????????? [3,1,10]
    // cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [3,1,10]
                            // ??????????????????????????? 1 ???????????????????????? [3]
                            // [3] ?????????????????? 3/1 = 3 ???????????? 3
    obj.addElement(49757);        // ??????????????? [3,1,10,5]
    cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [3,1,10]
    obj.addElement(27520);        // ??????????????? [3,1,10,5,5]
    obj.addElement(12303);        // ??????????????? [3,1,10,5,5,5]
    cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [3,1,10]
    obj.addElement(63945);        // ??????????????? [3,1,10,5,5,5]
    // cout << endl << obj.calculateMKAverage(); // ?????? 3 ???????????? [5,5,5]
                            // ??????????????????????????? 1 ???????????????????????? [5]
                            // [5] ?????????????????? 5/1 = 5 

    
    return 0;
}
