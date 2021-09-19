/*
leet215


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findKthLargest(vector<int> A, int k) {
        nth_element(A.begin(), A.begin()+k, A.end(), greater<int>{});
        return A[k-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findKthLargest( {3,2,1,5,6,4}, 2) << endl;
    cout << sol.findKthLargest( {3,2,3,1,2,4,5,5,6}, 4) << endl;
    return 0;
}
