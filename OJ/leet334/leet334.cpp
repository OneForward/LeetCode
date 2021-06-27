/*
leet334


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool increasingTriplet(const vector<int>& A) {
        int small = INT_MAX, mid = INT_MAX;
        for (auto&& big: A) {
            if (big > mid) return true;
            else if (big <= small) small = big;
            else mid = big;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << boolalpha;
    cout << sol.increasingTriplet({1,2,3,4,5}) << endl;
    cout << sol.increasingTriplet({5,4,3,2,1}) << endl;
    cout << sol.increasingTriplet({2,1,5,0,4,6}) << endl;
    return 0;
}
