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

#include <algorithm>
#include <vector>

int solution1(vector<int> A) {
    int N = A.size();
    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i] == A[j])
                result = max(result, abs(i - j));
    return result;
}

int solution(vector<int> A) {
    int N = A.size();
    int result = 0;
    int f[100005]{};
    for (int i = 0; i < N; i++) {
        auto x = A[i];
        f[x] = i; 
    }
    for (int i = 0; i < N; i++) {
        auto x = A[i];
        result = max(result, f[x] - i);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    cout << solution  ( {2, 1, 5, 1, 2, 2, 2} ) << endl;
    cout << solution  ( {4,6,2,2,6,6,1} ) << endl;
    cout << solution  ( {2, 2} ) << endl;
    
    return 0;
}
