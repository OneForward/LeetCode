/*
lcof46


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int translateNum(int x) {
        int f1 = 1, f2 = 0, prev = 0;
        while (x) {
            auto tmp = f1; 
            if (x % 10 and x % 10 * 10 + prev <= 25) f1 += f2;
            f2 = tmp; prev = x % 10; x /= 10;
        }
        return f1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.translateNum(12258) << endl;
    cout << sol.translateNum(506) << endl;
    cout << sol.translateNum(25) << endl;
    return 0;
}
