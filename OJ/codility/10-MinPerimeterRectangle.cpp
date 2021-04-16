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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#include <cmath>
int solution(int N) {
    int x = sqrt(N);
    for ( ; x >= 2; --x) {
        if (N % x == 0) break;
    }
    return 2 * (N / x  + x);
}



int main(int argc, char const *argv[])
{
    vector A = {1, 4, 5, 8}, B = {4, 5, 9, 10}, C = {4, 6, 7, 10, 2};
    cout << solution(36) << endl;
    cout << solution(48) << endl;
    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(30) << endl;
    cout << solution(101) << endl;
    cout << solution(5621892) << endl;
    cout << solution(INT_MAX) << endl;
    
    return 0;
}
