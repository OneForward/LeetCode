/*
leet581


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(const vector<int>& A) {
        int n = A.size(), lft = 1, rht = 0;
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            while (S.size() and A[S.back()] <= A[i] ) S.pop_back();
            if (S.size()) rht = i;
            S.push_back(i);
        }


        S.clear();
        for (int i = n-1; i >= 0; --i) {
            while (S.size() and A[S.back()] >= A[i] ) S.pop_back();
            
            if (S.size()) lft = i;
            S.push_back(i);
        }

        return rht - lft + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findUnsortedSubarray({2,6,4,8,10,9,15}) << endl;
    cout << sol.findUnsortedSubarray({1,2,3,4}) << endl;
    cout << sol.findUnsortedSubarray({1}) << endl;
    return 0;
}
