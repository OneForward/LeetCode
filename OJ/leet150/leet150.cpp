/*
leet150


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<int> S;
        for (auto &&token : tokens)
        {
            if (isdigit(token[0]) or token.size() > 1) {
                auto x = stoi(token);
                S.push(x);
            }
            else {
                auto b = S.top(); S.pop();
                auto a = S.top(); S.pop();
                if (token == "+") S.push(a + b);
                else if (token == "-") S.push(a - b);
                else if (token == "*") S.push(a * b);
                else if (token == "/") S.push(a / b);
            }
        }
        return S.top();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.evalRPN( { "2","1","+","3","*" } ) << endl;
    cout << sol.evalRPN( { "4","13","5","/","+" } ) << endl;
    return 0;
}
