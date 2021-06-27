/*
meituan0404


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;




int main(int argc, char const *argv[])
{
    // freopen("Q3in.txt", "r", stdin);

    int N, Kint, x;
    cin >> N >> Kint;
    auto K = to_string(Kint);

    string P[20005];
    // for (int x = 1; x <= 20000; ++x) P[x]  = "1";
    for (int x = 1; x <= 20000; ++x) {
        for (int y = x; y <= 20000; y += x) {
            P[y] += to_string(x);
        }
    }

    auto cnt = 0;
    while (N--)
    {
        cin >> x;
        // cout << x << " " << P[x] << endl;
        auto&& s = P[x];
        if (s.find(K) != s.npos) cnt++;
    }
    cout << cnt;
   
    
    return 0;
}
