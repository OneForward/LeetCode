/*
leet1696


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

class Solution {
public:
    int maxResult(vector<int> A, int K) {
        // 单调数列
        deque<int> Q; Q.push_back(0);
        int N = A.size();
        for (int i = 1; i < N; i++) {
            A[i] += A[Q.front()];
            while (Q.size() and A[Q.back()] <= A[i]) Q.pop_back();
            if (Q.size() and Q.front() == i - K) Q.pop_front();
            Q.push_back(i);
        }
        return A.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxResult({1,-1,-2,4,-7,3}, 2) << endl;
    cout << sol.maxResult({10,-5,-2,4,0,3}, 3) << endl;
    cout << sol.maxResult({1,-5,-20,4,-1,3,-6,-3}, 2) << endl;
    cout << sol.maxResult({122,-2920,1798,2421,-7678,-9915,4320,-2000,-9548,597,8936,-9358,-6455,-7726,2073,-6663,1692,-6049,7086,6556,-3851,2229,4559,5206,-7787,-9155,-3245,9256,3611,-824,4315,7473,3114,5157,7587,1557,4669,7989,-218,3401,-3125,-2048,5370,1400,-5237,-7032,-8641,4352,1629,2465,-8563,-9017,-1026,-4173,5364,-4536,-5932,-72,9829,-1258,-2851,6419,-2574,-7016,530,-1683,-6110,-1125,1840,1016,-1132,1182,4656,-7152,5582,-8187,1886,3212,4233,4357,-9575,6296,-8957,3862,-5852,-5324,8833,8524,7539,-2600,9462,-4339,8798,-3992,-8367,2108,7453,-417,3774,-9929,-7923,-4271,-2013,2064,6298,-8484,1326,-5976,3084,-2359,8769,4773,8942,6170,5976,2811,5729,-6190,-8586,1679,5360,-288,-8812,6095,-1925,-9241,-9614,-5734,-7241,6009,-4365,6289,3118,-3706,-4178,-276,8478,2308,530,7092,-3753,8659,9214,-3315,490,-5174,5388,5175,-9594,3510,3090,8307,2285,-141,-6180,-8067,7132,-6010,-5869,-7063,-8040,-6359,-1765,-7626,310,519,180,-1969,-8832,4021,-6416,6907,3997,-6163,8854,1643,1948,-7314,7365,2801,-5467,8881,8946,-5075,-9173,97,-8494,-1272,8937,-9555,4846,-8103,9108,-4791,-1482,5676,-9773,-8090,5213,-1120,-5134,3495,-8866,2134,8063,-980,-6785,8527,-2256,1667,-4011,-1112,4385,823,-5881,5120,9221,5020,8779,-6911,-6773,-6492,-9569,-5344,7569,2978,764,-4126,-5557,2125,-1516,6111,5163,-6171,-2255,-6969,1314,-9761,1809,4941,818,-7955,-9997,4786,-1799,325,-5192,7103,8185,7932,-2441,3971,-980,8356,8670,1083,-3384,-5976,-7204,-5421,8214,3339,1166,7744,2934,6059,-4570,-4115,-8947,-1087,-6579,2345,5423,9177,-6461,8056,6595,2085,4103,4020,8250,2887,8409,1104,-7105,4617,-9401,-4199,6050,5978,-4432,124,-8064,3653,-3889,-2973,-4933,-8635,3564,2494,5363,1704,5883,4193,8338,1381,-3674,7456,-2562,8542,9236,-1359,7870,9463,9824,7976,-1854,6992,4174,9718,-9535,8085,-7278,7543,5108,-3992,-4699,-9787,-5361,312,3437,-9579,-8575,2648,4702,1275,6739,3302,-6126,-3880,-6179,2880,1361,7618,-7936,-5509,4246,610,-7184,-2450,3701,-7819,4670,-4258,-6430,7796,7660,-4199,3461,-6917,-2327,2020,-4675,9407,-7613,3078,-6082,1335,6908,4676,-6180,2706,-6643,-714,-7122,-2017,-3377,2413,4275,6847,-9655,-1448,-9924,-7361,-2400,-6232,3949,7406,9737,3761,-8771,6060,1845,5717,-446,-5682,6041,461,-2502,4019,9256,3326,9201,8623,-2373,1057,3575,6198,4142,-9247,-754,1245,3762}, 743) << endl;
    return 0;
}
