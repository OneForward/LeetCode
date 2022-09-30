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

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        
        VI A(N), D(N), B(M);
        VI fA(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i] >> D[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> B[i];
        }
        
        
        for (auto&& money: B)
        {   
            map<int, int> S;
            for (int i = 0; i < N; i++)
            {
                auto T = (money - A[i]) / D[i];
                if (T < 0) continue;
                if (S.find(T) == S.end()) {
                    S[T] = i;
                }
                else S[T] = -1;
            }

            for (auto&& [_, i]: S) {
                if (i < 0) continue;
                fA[i]++;
                break;
            }
        }
        for (int i = 0; i < N-1; i++)
        {
            cout << fA[i] << " ";
        }
        cout << fA.back() << "\n";
    }
    
    return 0;
}
