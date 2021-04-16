/*
leet150


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
    int evalRPN(const vector<string>& tokens) {
        stack<int> S; int a, b;
        for (const auto& s: tokens) {
            
            if (s == "+") {
                b = S.top(); S.pop();
                a = S.top(); S.pop();
                S.push(a + b);
            }
            else if (s == "-") {
                b = S.top(); S.pop();
                a = S.top(); S.pop();
                S.push(a - b);
            }
            else if (s == "*") {
                b = S.top(); S.pop();
                a = S.top(); S.pop();
                S.push(a * b);
            }
            else if (s == "/"){
                b = S.top(); S.pop();
                a = S.top(); S.pop();
                S.push(a / b);
            }
            else 
                S.push(stoi(s));
        }
        return S.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.evalRPN({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"  } ) << endl;
    cout << sol.evalRPN({ "4", "13", "5", "/", "+" } ) << endl;
    cout << sol.evalRPN({ "2", "1", "+", "3", "*" } ) << endl;
    return 0;
}
