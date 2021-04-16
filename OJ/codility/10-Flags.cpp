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

// https://app.codility.com/demo/results/trainingR6HCKR-92J/
#include <cmath>
int solution(vector<int> &A) {
    int N = A.size();
    vector<bool> peaks(N);
    for (int i = 1; i < N-1; i++)
    {
        if (A[i] > A[i-1] and A[i] > A[i+1]) peaks[i] = true;
    }

    vector<int> next(N); next[N-1] = -1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (peaks[i]) next[i] = i;
        else next[i] = next[i+1];
    }
    
    int ans = 0, sqrtN = sqrt(N) + 1;
    for (int len = 1; len <= sqrtN; len++) {
        auto pos = 0, cnt = 0;
        while (pos < N) {
            pos = next[pos];
            if (pos == -1) break;
            cnt++;
            if (cnt >= len) break;
            pos += len;
        }
        ans = max(ans, cnt);
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector A = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << solution(A) << endl;
   
    
    return 0;
}
