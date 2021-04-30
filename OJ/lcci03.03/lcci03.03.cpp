/*
lcci03.03


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
using ipair=pair<int,int>;
using VD=vector<double>;
using VS=vector<string>;
using VP=vector<ipair>;
using VVP=vector<VP>;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

// 堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。 进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。

// 当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，popAt 应返回 -1.


class StackOfPlates {
public:
    vector<stack<int>> v{{}};
    size_t SIZE;

    StackOfPlates(int cap): SIZE(cap) {}
    
    void push(int val) {
        if (v.back().size() == SIZE) v.push_back({});
        if (SIZE) v.back().push(val);
    }
    
    int pop() {
        if (v.back().empty()) return -1;
        int x = v.back().top();
        v.back().pop();
        if (v.back().empty() and v.size() > 1) v.pop_back();
        return x;
    }
    
    int popAt(int index) {
        if (index >= v.size() or v[index].empty()) return -1;
        auto x = v[index].top();
        v[index].pop();
        if (v[index].empty() and v.size() > 1) v.erase(v.begin() + index);
        return x;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */


int main(int argc, char const *argv[])
{
    {
    StackOfPlates* obj = new StackOfPlates(1);
    obj->push(1);
    obj->push(2);
    cout << obj->popAt(1) << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    }
    {
    StackOfPlates* obj = new StackOfPlates(2);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->popAt(0) << endl;
    cout << obj->popAt(0) << endl;
    cout << obj->popAt(0) << endl;
    }
    
    return 0;
}
