/*
leet258


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int addDigits1(int num) {
        while (num >= 10) {
            auto ans = 0;
            while (num) {
                ans += num % 10; num /= 10;
            }
            num = ans;
        }
        return num;
    }
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.addDigits(38);

    return 0;
}
