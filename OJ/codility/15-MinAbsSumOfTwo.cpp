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
#include <climits>
#define ALL(A) A.begin(),A.end()

int solution(vector<int> &A) {
    sort(ALL(A));

    int N = A.size();
    int lft = 0, rht = N - 1, ans = INT_MAX;
    while (lft <= rht) {
        ans = min(abs(A[lft]+A[rht]), ans);
        if (A[lft] + A[rht] > 0) rht--;
        else lft++;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    { vector A = {1,4,-3}; cout << solution(A) << endl; }
    { vector A = {-3,-3,-1,-1,-1,0,0,1,2,2,2,2,3,3}; cout << solution(A) << endl; }
    { vector A = {0,0,1,2,2,2,2,3,3}; cout << solution(A) << endl; }
    { vector A = {1,2,2,2,2,3,3}; cout << solution(A) << endl; }
    { vector A = {1,2}; cout << solution(A) << endl; }
    { vector A = {1,1}; cout << solution(A) << endl; }
    { vector A = {-1,1}; cout << solution(A) << endl; }
    { vector A = {-1,0,1}; cout << solution(A) << endl; }
    { vector A = {-1,0,0,1}; cout << solution(A) << endl; }
    { vector A = {-1,0,0,0,0,1}; cout << solution(A) << endl; }
    { vector A = {-1,0,0,0,0,1,1,1,1,1}; cout << solution(A) << endl; }
    return 0;
}
