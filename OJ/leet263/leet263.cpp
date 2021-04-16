/*
leet263


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
    bool isUgly(int num) {
        if (num <= 0) return false;
        for (auto x: {2, 3, 5})
            while (num % x == 0) num /= x;
        return num == 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    for (auto x: {6, 8, 14}) cout << boolalpha << sol.isUgly(x) << endl;
    return 0;
}
