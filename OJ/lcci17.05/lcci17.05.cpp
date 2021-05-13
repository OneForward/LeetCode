/*
lcci17.05


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

class Solution1 {
public:
    vector<string> findLongestSubarray(const vector<string>& A) {
        int hash[200005], N = A.size();
        int f = 0, g = 0, pos = 0, len = 0;
        for (auto&& x: hash) x = -1;
        for (int i = 0; i < N; i++) {
            if (isdigit(A[i][0])) f++;
            else g++;
            auto& h = hash[f - g + 100000];
            if (h == -1 and f != g) h = i;
            else if (i - h > len) pos = h + 1, len = i - h;
        }
        return vector(A.begin()+pos, A.begin()+pos+len);
    }
};
class Solution {
public:
    vector<string> findLongestSubarray(const vector<string>& A) {
        int hash[200005]{}, N = A.size();
        int f = 0, g = 0, pos = 0, len = 0;
        // for (auto&& x: hash) x = -1;
        for (int i = 0; i < N; i++) {
            if (isdigit(A[i][0])) f++;
            else g++;
            cout << " f = " << f << endl;
            auto& h = hash[f - g + 100000];
            if (h == 0 and f != g) h = i + 1;
            else if (i + 1 - h > len) pos = h, len = i + 1 - h;
        }
        return vector(A.begin()+pos, A.begin()+pos+len);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findLongestSubarray({"d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"}) << endl;
    cout << sol.findLongestSubarray({"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"}) << endl;
    cout << sol.findLongestSubarray({"A","1"}) << endl;
    cout << sol.findLongestSubarray({"1","A", "A", "1", "A", "1", "1"}) << endl;
    cout << sol.findLongestSubarray({"A","A"}) << endl;
    return 0;
}
