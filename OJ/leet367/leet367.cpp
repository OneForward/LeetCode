/*
leet367


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(long long num) {
        // 0ms
        long long lft = 1, rht = num+1, mid;
        while (lft < rht) {
            mid = (lft + rht) / 2;
            if (mid * mid > num) rht = mid;
            else if (mid * mid < num) lft = mid + 1;
            else return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    for (int x = 1; x < 100; ++x)
    cout << "x = " << x << " : " << boolalpha << sol.isPerfectSquare(x) << endl;
    
    int x = 2000105819;
    cout << "x = " << x << " : " << boolalpha << sol.isPerfectSquare(x) << endl;
    return 0;
}
