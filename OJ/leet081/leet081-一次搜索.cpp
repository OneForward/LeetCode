/*
leet081


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool search(const vector<int>& A, int target) {
        if (target == A[0]) return true;

        int lft = 0, N = A.size(), rht = N, x0 = A[0];
        while (0 < rht and A[rht - 1] == x0) rht--;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (target < x0) {
                if (A[mid] < target or A[mid] >= x0) lft = mid + 1;
                else rht = mid;
            }
            else {
                if (A[mid] < target and A[mid] >= x0) lft = mid + 1;
                else rht = mid;
            }
        }
        return lft < N and A[lft] == target;
    }
};


int main(int argc, char const *argv[])
{

    Solution sol; 
    cout << boolalpha;
    cout << sol.search({1}, 1) << endl;
    cout << sol.search({1, 3}, 0) << endl;
    cout << sol.search({1, 0, 1, 1, 1}, 1) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 2) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 0) << endl;
    cout << sol.search({2,5,6,0,0,1,2}, 3) << endl;

    return 0;
}
