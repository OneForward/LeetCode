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
// #include "../../utils/LeetCpp.utils.hpp"

using namespace std;

#include <algorithm>
#include <vector>


int solution(vector<int> A) { // O(N^2)
    auto B = A;
    sort(B.begin(), B.end());

    enum State { isNeg, isPos };

    auto prevh = 0;
    long long ans = 0;
    for (auto&& h: B) {
        auto cnt = 0L; auto state = isNeg;
        for (auto&& x: A) {
            if (x >= h and state == isNeg) cnt++, state = isPos;
            else if (x < h and state == isPos) cnt++, state = isNeg;
        }
        if (state == isPos) cnt++;
        ans += cnt / 2 * (h - prevh); prevh = h;
        if (ans > 1'000'000'000) return -1;
    }
    return ans;
    
}


int main(int argc, char const *argv[])
{
    cout << solution  ( {1,3,2,1,2,1,5,3,3,4,2} ) << endl;
    cout << solution  ( {10,30,20,10,20,10,50,30,30,40,20,} ) << endl;
    cout << solution  ( {4,6,2,2,6,6,1} ) << endl;
    cout << solution  ( {5,8} ) << endl;
    cout << solution  ( {1,1,1,1} ) << endl;
    
    return 0;
}
