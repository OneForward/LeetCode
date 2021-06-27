/*
leet398


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    vector<int> A;
    Solution(const vector<int>& nums): A{nums} { }
    
    int pick(int target) {
        int K = 1, ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == target)  {
                if (K == 1 or rand() % K == 0) ans = i;
                K++;
            }
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,3,3};
    Solution solution = Solution(nums);

    // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
    cout << endl << solution.pick(3);

    // pick(1) 应该返回 0。因为只有nums[0]等于1。
    cout << endl << solution.pick(1); 
    return 0;
}
