/*
lcci04.10


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
using VP=vector<ipair>;
using VVP=vector<VP>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;



class Solution {
public:
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (not t1) return not t2;
        if (t1 and t2 and t1->val == t2->val) return isSame(t1->left, t2->left) and isSame(t1->right, t2->right);
        return false;
    };

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (not t1) return not t2;
        return isSame(t1, t2) or checkSubTree(t1->left, t2) or checkSubTree(t1->right, t2);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.checkSubTree( toTree({1, 2, 3}), toTree({2}) ) << endl;
    cout << sol.checkSubTree( toTree({1, null, 2, 4}), toTree({2, 4}) ) << endl;
    cout << sol.checkSubTree( toTree({1, null, 2, 4}), toTree({3, 4}) ) << endl;
    return 0;
}
