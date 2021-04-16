/*
leet135


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int candy(const vector<int>& A) {
        // Time O(N) Space O(N) 两次遍历
        int n = A.size();
        
        vector<int> f(n, 1); 
        for (int i = 1; i < n; i++)
        {
            if (A[i] > A[i-1]) f[i] = max(f[i], f[i-1]+1);
        }
        for (int i = n-2; i >= 0; i--)
        {
            if (A[i] > A[i+1]) f[i] = max(f[i], f[i+1]+1);
        }
        return reduce(f.begin(), f.end(), 0);
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.candy({1,6,10,8,7,3,2}) << endl;
    cout << sol.candy({1,2,87,87,87,2,1}) << endl;
    cout << sol.candy({1,0,2}) << endl;
    cout << sol.candy({1,2,2}) << endl;
    return 0;
}
