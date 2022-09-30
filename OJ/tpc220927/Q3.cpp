/*
tpc220927


*/

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string_view>
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
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

using LL = long long int;
const int MOD = 998244353;
int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N ;
        
        VI A(N); 
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cin >> M;
        
        VI C(M+1); 
        for (int i = 0; i <= M; i++)
        {
            cin >> C[i];
        }
         
        // for (int i = 0; i < M-1; i++)
        // {
        //     cout << fA[i] << " ";
        // }
        // cout << fA.back() << "\n";
    }
    
    return 0;
}
