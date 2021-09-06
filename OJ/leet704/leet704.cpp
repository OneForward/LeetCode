/*
leet704


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int search(const vector<int>& A, int x) {
        int N = A.size();
        int lft = 0, rht = N;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (A[mid] >= x) rht = mid;
            else lft = mid + 1;
        }

        return (lft < N and A[lft] == x) ? lft : -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.search({-1,0,3,5,9,12}, 9) << endl;
    cout << sol.search({-1,0,3,5,9,12}, 2) << endl;
    return 0;
}
