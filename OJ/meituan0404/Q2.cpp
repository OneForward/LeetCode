/*
meituan0404


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;




int main(int argc, char const *argv[])
{
    // freopen("Q2in.txt", "r", stdin);

    int N, type, x;
    int Counter[2]{1, 0}; // 纬度, 经度
    cin >> N;
    while (N--) {
        cin >> type >> x;
        Counter[type]++;
    }
    cout << Counter[0] * (Counter[1] == 0 ? 1 : Counter[1] * 2);
    return 0;
}
