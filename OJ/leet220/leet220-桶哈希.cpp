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

    bool containsNearbyAlmostDuplicate(const vector<int>& A, int k, int t) {
        // 桶哈希 O(N)
        int N = A.size();

        auto T = (long long)t + 1;
        auto hash = [&](int x) {
            auto mod = x % T;
            if (mod < 0) mod += T;
            return (x - mod) / T;
        };
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++)
        {
            auto bucket = hash(A[i]);
            if (M.find(bucket) != M.end()) return true;
            if (M.find(bucket+1) != M.end() and (long long)M[bucket+1] - A[i] <= t ) return true;
            if (M.find(bucket-1) != M.end() and (long long)A[i] - M[bucket-1] <= t ) return true;
            M[bucket] = A[i];

            if ((int)M.size() >= k) M.erase(M.find(hash(A[i-k])));
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,2,3,1}, 3, 0) << endl;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate({2147483647, -1, 2147483647}, 1, 2147483647) << endl;
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({8,7,15,1,6,1,9,15}, 1, 3) << endl;
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,0,1,1}, 1, 2) << endl;
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({1,5,9,1,5,9}, 2, 3) << endl;
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({-1, 2147483647}, 1, 2147483647) << endl;
    // cout << boolalpha << sol.containsNearbyAlmostDuplicate({-2147483648, -2147483647}, 3, 3) << endl;
    return 0;
}
