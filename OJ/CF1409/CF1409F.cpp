/*
CF1409


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;




int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);

    int N, K, M; string S, T;
    cin >> N >> K >> S >> T;

    M = T.size();
    vector<vector<vector<int>>> f(N+1, vector<vector<int>>(M+1, vector<int>(K+1)));
    for (int i = 0; i <= N; i++) f[i][0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                f[i][j][k] = f[i-1][j][k];
                if (S[i-1] == T[j-1]) f[i][j][k] += f[i-1][j-1][k];
                else if (k > 0) f[i][j][k] += f[i-1][j-1][k-1];
            }
        }
        
    }

    cout << f << endl;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int k = 0; k <= K; k++)
        {
            ans = max(ans, f[i][M][k]);
        }
            
    }
    cout << ans << endl;
    return 0;
}
