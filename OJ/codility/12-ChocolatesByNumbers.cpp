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

int solution(int N, int M) {
    auto gcd = [](int x, int y) {
        if (y) while ((x %= y) and (y %= x) );
        return x + y;
    };
    return N / gcd(N, M);
}




int main(int argc, char const *argv[])
{
    cout << solution(10, 4) << endl;
    
    return 0;
}
