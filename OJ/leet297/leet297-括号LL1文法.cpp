/*
leet297


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



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (not root) return "X";
        auto lft = "(" + serialize(root->left) + ")" ;
        auto rht = "(" + serialize(root->right) + ")" ;
        return lft + to_string(root->val) + rht;
    }
    
    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0';
        }
        return x * sgn;
    }
 
    TreeNode* _desrialize(const string& data, int& p) {
        if ( data[p] == 'X' ) { p++; return {}; }
        auto root = new TreeNode{};
        
        ++p; root->left = _desrialize(data, p); ++p;
        root->val = parseInt(data, p);
        ++p; root->right = _desrialize(data, p); ++p;
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return _desrialize(data, p);
    }
};


int main(int argc, char const *argv[])
{
    Codec ser, deser;
    // cout << toTree( {1,2,3,null,null,4,5} ) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,2,3,null,null,4,5,6,7} ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,12,3,null,null,4,5} ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( { } ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1, } ) )) << endl;
    cout << deser.deserialize(ser.serialize( toTree( {1,12, } ) )) << endl;
    return 0;
}
