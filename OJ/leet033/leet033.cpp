/*
leet033


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;


class Solution {
public:

    int search(const vector<int>& A, int target) {
        // 一次搜索
        const int x0 = A[0], N = A.size();
        int lft = 0, rht = N;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (target < x0) {
                if (A[mid] < target or A[mid] >= x0 ) lft = mid + 1;
                else rht = mid;
            }
            else {
                if (A[mid] < target and A[mid] >= x0 ) lft = mid + 1;
                else rht = mid;
            }
        }
        if (lft == N or A[lft] != target) return -1;
        return lft;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.search({1,3},2) << endl;
    cout << sol.search({1}, 0) << endl;
    cout << sol.search({4,5,6,7,0,1,2}, 0) << endl;
    cout << sol.search({4,5,6,7,0,1,2}, 2) << endl;
    cout << sol.search({4,5,6,7,0,1,2}, 3) << endl;
    cout << sol.search({4,5,6,7,0,1,2}, 4) << endl;
    cout << sol.search({4,5,6,7,0,1,2}, 8) << endl;
    return 0;
}
