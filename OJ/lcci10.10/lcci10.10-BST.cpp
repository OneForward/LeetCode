/*
lcci10.10


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

/**
 * 每个结点多维护一项信息，即，左子树的结点数
 * 当插入一个结点时，插入到左子树，其父结点计数+1
 * 插入到右子树，计数默认1
 * 当查找一个结点时，查找如果往右子树的，总数 ans 则加上其父结点的计数
 * 最终得到的ret + 找到的结点自身 = ans + 1
 */
class StreamRank
{
    struct TreeNode
    {
        int sum{1}; // 左子树大小
        int data{}; // 键值
        TreeNode *lft{};
        TreeNode *rht{};
        TreeNode(int x = 0): data{x} {}
    };

    TreeNode* root{};

    void insert(TreeNode*& root, int x) {
        if (not root) { root = new TreeNode{x}; return; }

        if (x < root->data) {
            root->sum++; insert(root->lft, x);
        }
        else if (x == root->data) {
            root->sum++; 
        }
        else {
            insert(root->rht, x);
        }
    }

    int search(TreeNode* root, int x) {
        if (not root) return 0;
        if (x < root->data) return search(root->lft, x);
        if (x == root->data) return root->sum;
        return search(root->rht, x) + root->sum;
    }

public:
    StreamRank() {}

    void track(int x)
    {
        insert(root, x);
    }

    int getRankOfNumber(int x)
    {
        return search(root, x);
    }

};


int main(int argc, char const *argv[])
{
    // Solution sol;   
    StreamRank sol;
    cout << sol.getRankOfNumber(1) << endl;
    sol.track(0);
    cout << sol.getRankOfNumber(0) << endl;
    return 0;
}
