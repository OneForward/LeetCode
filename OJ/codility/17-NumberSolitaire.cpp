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
    auto n = A.size();
    auto f = A;
    for (int i = 1; i < n; ++i) {
        auto maxVal = INT_MIN;
        for (int k = 1; k <= 6; ++k) {
            if (i >= k) maxVal = max(f[i-k], maxVal);
        }
        f[i] += maxVal;
    }
    return f.back();
}


int main(int argc, char const *argv[])
{
    cout << solution  ( {1,-2,0,9,-1,-2} ) << endl;
    // cout << solution  ( {} ) << endl;
    // cout << solution  ( {1} ) << endl;
    // cout << solution  ( {-1} ) << endl;
    // cout << solution  ( {} ) << endl;
    // cout << solution  ( {2,} ) << endl;
    // cout << solution  ( {2,3} ) << endl;
    // cout << solution  ( {2,3,4} ) << endl;
    // cout << solution  ( {2,3,4,5} ) << endl;
    // cout << solution  ( {2,3,4,6} ) << endl;
    
    return 0;
}
