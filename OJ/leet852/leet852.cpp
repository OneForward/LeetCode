/*
leet852


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& A) {
        int lft = 1, rht = A.size() - 1;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (A[mid-1] < A[mid] and A[mid] < A[mid+1])  lft = mid + 1;
            else rht = mid;
        }
        return lft;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.peakIndexInMountainArray({0, 1, 0}) << endl;
    cout << sol.peakIndexInMountainArray({0, 2, 1, 0}) << endl;
    cout << sol.peakIndexInMountainArray({0, 10, 5, 2}) << endl;
    cout << sol.peakIndexInMountainArray({3, 4, 5, 1}) << endl;
    cout << sol.peakIndexInMountainArray({24,69,100,99,79,78,67,36,26,19}) << endl;
    return 0;
}
