/*
shopee0802


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;




class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * find balanced index for an input array
     * @param inputArray int整型vector the input array
     * @return int整型
     */
    int findBalancedIndex(const vector<int>& A) {
        // write code here
        int sum = accumulate(ALL(A), 0);
        int f = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (sum - A[i] == f * 2) return i;
            f += A[i];
        }
        return -1;        
        
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findBalancedIndex({1,2,3,4,6}) << endl;
    return 0;
}
