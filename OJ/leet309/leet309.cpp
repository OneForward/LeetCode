/*
leet309


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        // O(N)
        int buy0 = INT_MIN, sell0 = 0, sell1 = 0;
        for (const auto& x: prices) {
            // sell0: 昨天售出的
            // sell1: 前天售出的
            buy0 = max(buy0, sell1-x);
            sell1 = sell0;
            sell0 = max(sell0, buy0+x);
        }
        return sell0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxProfit({1,2,3,0,2}) << endl;
    return 0;
}
