/*
leet462


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int minMoves2(vector<int> A) {
        int N = A.size() / 2;
        nth_element(A.begin(), A.begin() + N , A.end());

        int ans = 0;
        for (auto&& x: A) ans += abs(x - A[N]);
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minMoves2({1,2,3}) << endl;
    cout << sol.minMoves2({1,10,2,9}) << endl;
    return 0;
}
