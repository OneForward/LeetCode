/*
lcof11


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int minArray(const vector<int>& A) {
        int lft = 0, rht = A.size(), v0 = A[0];
        while (rht >= 1 and A[rht-1] == v0) rht--;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (A[mid] < v0) rht = mid;
            else lft = mid + 1;
        }
        return lft < A.size() ? A[lft] : A[0];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minArray({3,4,5,1,2}) << endl;
    cout << sol.minArray({2,2,2,0,1}) << endl;
    cout << sol.minArray({1,3,5}) << endl;
    cout << sol.minArray({3,3,3}) << endl;
    cout << sol.minArray({3,1,3,3}) << endl;

    return 0;
}
