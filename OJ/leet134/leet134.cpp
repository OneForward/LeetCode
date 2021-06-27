/*
leet134


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int x = 0, minx = INT_MAX, mini = 0, n = gas.size();
        for (int i = 0; i < n; i++)
        {
            x += gas[i] - cost[i];
            if (x < minx) minx = x, mini = i;
        }
        return x >= 0 ? (mini + 1) % n : -1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.canCompleteCircuit({1,2,3,4,5}, {3,4,5,1,2}) << endl;
    cout << sol.canCompleteCircuit({2,3,4}, {3,4,3}) << endl;
    return 0;
}
