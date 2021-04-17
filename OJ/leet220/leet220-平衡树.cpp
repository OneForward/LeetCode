/*
leet220


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:

    bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
        // set O(N log K)
        set<int> S;
        for (int i = 0; i < nums.size(); ++i) {
            auto s = S.lower_bound(nums[i]);
            if (s != S.end() and *s <= (long long)nums[i] + t) return true;

            if ( s != S.begin() and *prev(s) >= (long long)nums[i] - t) return true;

            S.insert(nums[i]);

            if (S.size() > k) S.erase(nums[i-k]);
        }
        return false;
    }
    
    bool containsNearbyAlmostDuplicate2(const vector<int>& A, int k, int t) {
        // multiset O(N log K)
        int N = A.size();
        if (N == 0 or k == 0) return false;
        
        multiset<int> S;
        for (int i = 0; i < min(N, k+1); ++i) S.insert(A[i]);
        
        auto p = S.begin(), pnext = next(p);
        while (pnext != S.end()) {
            if ((long)*pnext - *p <= t) return true;
            p = pnext; pnext++;
        }
        for (int i = k+1; i < N; ++i) {
            S.erase(S.find(A[i-k-1])); 
            auto p = S.insert(A[i]);
            if (next(p) != S.end() and (long)*next(p) - *p <= t) return true;
            if (p != S.begin() and (long)*p - *prev(p) <= t) return true;
        }
        return false;
    }

};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,2,3,1}, 3, 0) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,0,1,1}, 1, 2) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,5,9,1,5,9}, 2, 3) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({-1, 2147483647}, 1, 2147483647) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({-2147483648, -2147483647}, 3, 3) << endl;
    return 0;
}
