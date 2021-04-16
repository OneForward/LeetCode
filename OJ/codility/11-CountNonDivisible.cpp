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

#include <unordered_map>
#include <cmath>
vector<int> solution(vector<int> &A) {
    unordered_map<int, int> M;
    for (auto&& x: A) M[x]++;

    int N = A.size();
    vector<int> ans; ans.reserve(N);
    for (auto&& x: A) {
        int cnt = 0, sqrtN = sqrt(x);
        for (int d = 1; d <= sqrtN; ++d) {
            if (x % d == 0) {
                if (M.find(d) != M.end()) cnt += M[d];
                if (x / d != d and M.find(x / d) != M.end()) 
                    cnt += M[x / d];
            }
        }
        ans.push_back(N - cnt);
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector A = {1, 1, 3, 9, 9, 81, 81};
    cout << solution(A) << endl;
    
    return 0;
}
