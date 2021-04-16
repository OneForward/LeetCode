/*
leet919


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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    vector<TreeNode*> v;
    CBTInserter(TreeNode* root) {
        v = {{}};
        queue<TreeNode*> Q; 
        if (root) Q.push(root);
        while (Q.size()) {
            auto root = Q.front(); Q.pop();
            v.push_back(root);
            if (root->left) Q.push(root->left);
            if (root->right) Q.push(root->right);
        }
    }
    
    int insert(int x) {
        auto leaf = new TreeNode{x};
        int root = v.size() / 2;
        v.push_back(leaf);
        if (v.size() & 1) v[root]->left = leaf;
        else v[root]->right = leaf;

        return v[root]->val;
    }
    
    TreeNode* get_root() {
        return v[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main(int argc, char const *argv[])
{
    CBTInserter sol{ toTree({1}) };
    cout << sol.insert(2) << endl;
    cout << sol.get_root() << endl;
    // CBTInserter sol{ toTree({1,2,3,4,5,6}) };
    // cout << sol.insert(7) << endl;
    // cout << sol.insert(8) << endl;
    // cout << sol.get_root() << endl;

    return 0;
}
