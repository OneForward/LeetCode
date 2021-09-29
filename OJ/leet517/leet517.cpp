/*
leet517


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int findMinMoves(const VI& machines) {
        auto sum = reduce(ALL(machines), 0);
        int N = (int)machines.size();
        if (sum % N) return -1;

        auto avg = sum / N;
        int ans = 0, s = 0;
        for (auto&& x: machines) {
            auto dx = x - avg;
            s += dx;
            ans = max({ans, abs(dx), abs(s)});
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findMinMoves({1,0,5}) << endl;
    cout << sol.findMinMoves({0,3,0}) << endl;
    cout << sol.findMinMoves({0,2,0}) << endl;
    cout << sol.findMinMoves({0,0,11,5}) << endl;
    return 0;
}
