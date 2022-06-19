/*
leet532


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findPairs(vector<int> A, int k) {
        sort(ALL(A));
        int lft = 0, rht = 1, N = A.size();
        int ans = 0;
        int prev = INT_MAX;
        while (rht < N) {
            auto x = A[rht] - A[lft];
            if (x == k )  {
                if (prev != A[lft]) ans++;
                prev = A[lft];
                rht++, lft++;
            }
            else if (x < k) rht++;
            else lft++;
            if (lft == rht) rht++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findPairs({1,1,1,2,2,2,2,2,3,3,3,}, 1) << endl;
    cout << sol.findPairs({3, 1, 4, 1, 5}, 2) << endl;
    cout << sol.findPairs({1, 2, 3, 4, 5}, 1) << endl;
    cout << sol.findPairs({3, 1, 4, 1, 5}, 0) << endl;
    return 0;
}
