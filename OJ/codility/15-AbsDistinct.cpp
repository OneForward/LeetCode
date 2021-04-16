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

int solution(vector<int> &A) {
    int N = A.size(), lft = 0, rht = N - 1, ans = N;
    while (lft < rht) {
        if (A[lft] == A[lft+1]) lft++, ans--;
        else if (A[rht] == A[rht-1]) rht--, ans--;
        else if (A[lft] == -A[rht]) lft++, ans--;
        else if (A[lft] > -A[rht]) rht--;
        else lft++;
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    { vector A = {-5, -3 , -1, 0, 0, 3, 6}; cout << solution(A) << endl; }
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
