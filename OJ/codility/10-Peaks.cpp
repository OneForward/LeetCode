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

// https://app.codility.com/demo/results/trainingTPWWUW-WVX/
int solution(vector<int> &A) {
    int N = A.size();
    vector<int> peaks;
    for (int i = 1; i < N-1; i++)
    {
        if (A[i] > A[i-1] and A[i] > A[i+1]) peaks.push_back(i);
    }

    
    int ans = 0;
    for (int len = 1; len <= N; len++) {
        if (N % len) continue;
        auto block = -1;
        for (auto&& p: peaks) {
            if (p / len > block + 1) break;
            block = p / len;
        }
        if (block == N / len - 1) ans = max(ans, N / len);
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector A = {1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << solution(A) << endl;
   
    
    return 0;
}
