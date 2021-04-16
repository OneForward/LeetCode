/*
leet448


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> A) {
        vector<int> ans;
        for (auto x: A) { 
            x = abs(x);
            if (A[x-1] > 0) A[x-1] = -A[x-1];
        }
        for (int i = 0; i < A.size(); ++i) { 
            if (A[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findDisappearedNumbers({4,3,2,7,8,2,3,1}) << endl;
    return 0;
}
