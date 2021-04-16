/*
leet480


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
#include <utility>
#include "../utils/LeetCpp.utils.hpp"


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:

    vector<double> medianSlidingWindow(const vector<int>& A, int k) {
        // PBDS ordered tree, 68ms, 25MB
        tree<pair<int, int>, null_type, less<pair<int, int>>, 
            rb_tree_tag, tree_order_statistics_node_update> t;
        int n = A.size();
        vector<double> ans; ans.reserve(n-k+1);
        for (int i = 0; i < k; ++i) t.insert({A[i], i});
        for (int i = k; ; ++i) { 
            long x = (*t.find_by_order(k / 2)).first;
            long y = (*t.find_by_order((k - 1) / 2)).first;
            ans.push_back((x + y) / 2.0);
            
            if (i == n) break;
            t.erase({A[i-k], i-k}); 
            t.insert({A[i], i});
        }  
        return ans;  
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.medianSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << endl;
    cout << sol.medianSlidingWindow({1,2,3,4,2,3,1,4,2}, 3) << endl;
    cout << sol.medianSlidingWindow({2,2}, 2) << endl;
    return 0;
}
