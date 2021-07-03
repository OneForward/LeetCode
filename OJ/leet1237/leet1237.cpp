/*
leet1237


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y) { return x + y; } ;
};

class Solution {
public:
    vector<vector<int>> findSolution( CustomFunction customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; x++)
        {
            int lft = 1, rht = 1001;
            while (lft < rht) {
                auto y = (lft + rht) / 2;
                if (customfunction.f(x, y) >= z) rht = y;
                else lft = y + 1;
            }
            auto y = lft;
            while (customfunction.f(x, y) == z) ans.push_back({x, y}), y++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findSolution(CustomFunction{}, 5) << endl;
    return 0;
}
