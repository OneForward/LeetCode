/*
leet213


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"
using namespace std;

#define ALL(A) A.begin(),A.end()
#define MAX(A) *max_element(ALL(A))

class Solution {
public:
    int rob(const vector<int>& A) {

        int N = A.size(), ans = 0;
        if (N <= 3) return MAX(A);

        {vector f = A; 
        f[2] += f[0];
        for (int rht = 3; rht < N-1; rht++) {
            f[rht] = max(f[rht-2] , f[rht-3] ) + A[rht];
        }
        ans = max(MAX(f), ans);}

        {vector f = A; 
        f[3] += f[1];
        for (int rht = 4; rht < N; rht++) {
            f[rht] = max(f[rht-2] , f[rht-3] ) + A[rht];
        }
        ans = max(MAX(f), ans);}
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.rob({0}) << endl;
    cout << sol.rob({1}) << endl;
    cout << sol.rob({2,3,2}) << endl;
    cout << sol.rob({1,2,3,1}) << endl;
    cout << sol.rob({1,2,1,1}) << endl;
    cout << sol.rob({2,7,9,3,1}) << endl;
    cout << sol.rob({2,3,9,32,2,2,3,1,2,3,4,5,2}) << endl;
    return 0;
}
