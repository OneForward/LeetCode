/*
leet958


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
    bool isCompleteTree(TreeNode* root) {
        const int N = 105;
        TreeNode* tree[N]{nullptr, root};
        queue<int> Q; Q.push(1);
        while (Q.size()) {
            auto i = Q.front(); Q.pop();
            auto root = tree[i];
            if (root->left) {
                if (i * 2 >= N) return false;
                Q.push(i * 2), tree[i * 2] = root->left ;
            }
            if (root->right) {
                if (i * 2 + 1 >= N) return false;
                Q.push(i * 2 + 1), tree[i * 2 + 1] = root->right;
            }
        }
        int i = 1;
        for (; tree[i]; ++i);
        for (; i < N and not tree[i]; ++i);
        return i == N;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.isCompleteTree( toTree( {1,2,3,4,5,6} ) ) << endl;
    cout << sol.isCompleteTree( toTree( {1,2,3,4,5,null,7} ) ) << endl;
    return 0;
}
