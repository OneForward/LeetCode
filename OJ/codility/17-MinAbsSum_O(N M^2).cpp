/*
codility


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

int solution( vector<int> A) {
    // this solution is hard to think out
    if (A.empty()) return 0;

    auto sum = 0;
    int counts[101]{};
    for (auto& x: A) x = abs(x), sum += x, counts[x]++;

    vector<int> f(sum+1, -1); f[0] = 0;
    for (int x = 1; x <= 100; ++x) {
        if (counts[x] == 0) continue;
        for (int S = 0; S <= sum; ++S) {
            if (f[S] >= 0) f[S] = counts[x];
            else if ( S >= x and f[S - x] > 0 ) f[S] = f[S - x] - 1;
        }
    }
    int ans = sum;
    for (int S = 0; S <= sum / 2; ++S) if (f[S] >= 0) ans = min(ans, sum - 2 * S);
    return ans;
}


int main(int argc, char const *argv[])
{
    // cout << solution  ( {1,5,2,-2} ) << endl;
    cout << solution  ( {10, 1, 1, 1, 1, 1, 1} ) << endl;
    cout << solution  ( {2,} ) << endl;
    cout << solution  ( {2,3} ) << endl;
    cout << solution  ( {2,3,4} ) << endl;
    cout << solution  ( {2,3,4,5} ) << endl;
    cout << solution  ( {2,3,4,6} ) << endl;
    
    return 0;
}
