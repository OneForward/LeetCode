/*
leet172


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
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n) {
            n /= 5;
            cnt += n; 
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.trailingZeroes(100) << endl;
    cout << sol.trailingZeroes(3) << endl;
    cout << sol.trailingZeroes(5) << endl;
    return 0;
}
