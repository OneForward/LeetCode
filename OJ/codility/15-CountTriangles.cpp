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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(A) A.begin(),A.end()
int solution(vector<int> &A) {
    int N = A.size(), ans = 0;
    sort(ALL(A));
    FOR(z, 2, N) {
        auto y = z - 1;
        FOR(x, 0, z) {
            while (y >= 0 and A[x] + A[y] > A[z]) y--;
            ans += min(z - x - 1, z - y - 1);
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    { vector A = {10, 2, 5, 1, 8, 12}; cout << solution(A) << endl; }
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
