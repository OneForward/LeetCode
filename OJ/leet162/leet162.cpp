/*
leet162


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findPeakElement(const vector<int>& A) {
        // 注意到终止条件是 lft < rht, 因此 mid 永远取不到 rht (取到时已经 结束循环了)
        int lft = 0, rht = (int)A.size() - 1;
        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (A[mid] > A[mid+1]) rht = mid;
            else lft = mid + 1;
        }
        return lft;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findPeakElement({1,2,3,1}) << endl;
    cout << sol.findPeakElement({1,2,1,3,5,6,4}) << endl;
    return 0;
}
