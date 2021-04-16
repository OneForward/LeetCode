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

int solution(const vector<int> &A) {
    if (A.empty()) return 0;

    unordered_set<int> S = {abs(A[0])};
    for (int i = 1; i < A.size(); ++i) {
        auto x = A[i];
        auto tmp = S; S.clear();
        for (auto&& si: tmp) S.insert(si + abs(x)), S.insert(abs(si - abs(x)));
    }
    return *min_element(S.begin(), S.end());
}


int main(int argc, char const *argv[])
{
    cout << solution  ( {1,5,2,-2} ) << endl;
    cout << solution  ( {2,} ) << endl;
    cout << solution  ( {2,3} ) << endl;
    cout << solution  ( {2,3,4} ) << endl;
    cout << solution  ( {2,3,4,5} ) << endl;
    cout << solution  ( {2,3,4,6} ) << endl;
    
    return 0;
}
