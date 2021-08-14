/*
拼多多0808


*/

// #include "../utils/LeetCpp.utils.hpp"


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
using namespace std;
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;




int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);

    
    
    int N, T, C, x;
    cin >> N >> T >> C;

    vector<int> P = {0};
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        if (x > T) {
            P.push_back(i);
        }
    }
    P.push_back(N + 1);

    int ans = 0;
    for (size_t i = 0; i + 1 < P.size(); i++)
    {
        auto lft = P[i] + 1;
        auto rht = P[i + 1];
        ans += max(rht - lft - C + 1, 0);
    }
    
    cout << ans;


    return 0;
}
