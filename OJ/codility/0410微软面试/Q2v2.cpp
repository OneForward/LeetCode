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



int solution(vector<int> A) { // O(N)
    A.push_back(0);

    int N = A.size(), ans = 0;
    stack<int> S;

    for (int i = N - 1; i >= 0; i--)
    {
        auto x = A[i];
        while (S.size() and A[S.top()] >= x) S.pop();
        if (S.size() and S.top() == i + 1) ans += A[i] - A[i+1]; S.push(i);
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
