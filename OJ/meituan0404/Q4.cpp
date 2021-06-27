/*
meituan0404


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;




int main(int argc, char const *argv[])
{
    // freopen("Q4in.txt", "r", stdin);
    // freopen("Q4in2.txt", "r", stdin);

    int N, K, x;
    cin >> N >> K;

    vector<pair<int, int>> Q[10000];

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cin >> x;
            Q[x].push_back({r, c});
        }
    }

    for (int x = 1; x <= K; x++)
    {
        if (Q[x].empty()) {
            cout << -1; return 0;
        }
    }
    
    int ans = 0;
    for (int x = 1; x < K; x++) {
        int dist = 99999999;
        for (auto&& q1: Q[x]) {
            auto r1 = q1.first, c1 = q1.second;
            for (auto&& q2: Q[x+1]) {
                auto r2 = q2.first, c2 = q2.second;
                dist = min(dist, abs(r1-r2) + abs(c1-c2) );
            }
        }
        ans += dist > 1000000 ? 0 : dist;
    }
    cout << ans;



    
   
    
    return 0;
}
