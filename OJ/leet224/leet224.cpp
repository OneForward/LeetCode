/*
leet224


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> op; op.push(1);
        int sign = 1, n = s.size(), ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case ' ': break;
            case '+': sign = 1; break;
            case '-': sign = -1; break;
            case '(': op.push(sign * op.top()); sign = 1; break;
            case ')': op.pop(); break;
            default:
                int x = 0;
                while (i < n and isdigit(s[i]))
                {
                    x = x * 10 + (s[i] - '0');
                    i++;
                } i--;
                ans += sign * op.top() * x;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.calculate("- (3 + (4 + 5))") << endl;
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << sol.calculate(" 2-1 + 2 ") << endl;
    cout << sol.calculate("1 + 1") << endl;
    return 0;
}
