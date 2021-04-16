/*
lcp034


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

    int maxValue(TreeNode* root, int k) {
        function<vector<int>(TreeNode*)> f = [&](TreeNode* root) {
            if (not root) return vector<int>(k+1);
            auto lft = f(root->left), rht = f(root->right);
            vector<int> ans(k+1);
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; i + j < k; j++)
                {
                    ans[i+j+1] = max(ans[i+j+1], lft[i] + rht[j] + root->val);
                }
            }

            for (int i = 0; i <= k; i++)
            {
                for (int j = 0; j <= k; j++)
                {
                    ans[0] = max(ans[0], lft[i] + rht[j]);
                }
            }

            return ans;
        };

        auto ans = f(root);
        return *max_element(ans.begin(), ans.end());
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxValue( toTree({5,2,3,4}), 2 ) << endl;
    cout << sol.maxValue( toTree({8,1,3,9,9,9,null,9,5,6,8}), 2 ) << endl;
    return 0;
}
