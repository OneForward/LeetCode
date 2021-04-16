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


#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
const long long MAX = 1'000'000'000;

int solution(int M, vector<int> &A) {
    int N = A.size();
    bool f[100005]{};
    long long lft = 0, ans = 0;
    
    REP(rht, N) {
        if (f[A[rht]]) {
            while (A[lft] != A[rht]) ans += rht - lft, f[A[lft]] = false, lft++;
            ans += rht - lft, lft++;
            if (ans > MAX) return  MAX;
        }
        f[A[rht]] = true;
    }
    ans += (N - lft) * (N - lft + 1) / 2;
    return min(ans, MAX);
}




int main(int argc, char const *argv[])
{
    // { vector A = {1}; cout << solution(1000, A) << endl; }
    { vector A = {3,4,5,5,2}; cout << solution(1000, A) << endl; }
    { vector A = {-3,-3,-1,-1,-1,0,0,1,2,2,2,2,3,3}; cout << solution(1000, A) << endl; }
    { vector A = {0,0,1,2,2,2,2,3,3}; cout << solution(1000, A) << endl; }
    { vector A = {1,2,2,2,2,3,3}; cout << solution(1000, A) << endl; }
    { vector A = {1,2}; cout << solution(1000, A) << endl; }
    { vector A = {1,1}; cout << solution(1000, A) << endl; }
    { vector A = {-1,1}; cout << solution(1000, A) << endl; }
    { vector A = {-1,0,1}; cout << solution(1000, A) << endl; }
    { vector A = {-1,0,0,1}; cout << solution(1000, A) << endl; }
    { vector A = {-1,0,0,0,0,1}; cout << solution(1000, A) << endl; }
    { vector A = {-1,0,0,0,0,1,1,1,1,1}; cout << solution(1000, A) << endl; }
    return 0;
}
