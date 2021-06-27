/*
leet334


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    bool increasingTriplet(const vector<int>& A) {
        int n = A.size();
        vector<int> lft(n, n), rht(n);
        vector<int> S; S.reserve(n);
        for (int i = 0; i < n; ++i) {
            while (S.size() and A[S.back()] >= A[i]) S.pop_back();
            if (S.size()) lft[i] = S.back();
            S.push_back(i);
        }
        
        S.clear();
        for (int i = n-1; i >= 0; --i) {
            while (S.size() and A[S.back()] <= A[i]) S.pop_back();
            if (S.size()) rht[i] = S.back();
            S.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (lft[i] < i and i < rht[i]) return true;
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
