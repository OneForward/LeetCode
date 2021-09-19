/*
leet167


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& v, int target) {
        // 双指针法
        int lft = 0, rht = (int)v.size()-1;
        while (lft < rht) {
            int sum = v[lft] + v[rht];
            if (sum == target) return {lft+1, rht+1};
            else if (sum < target) lft++;
            else rht--;
        }
        return {};
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.twoSum({2,7,11,15}, 9) << endl;
    return 0;
}
