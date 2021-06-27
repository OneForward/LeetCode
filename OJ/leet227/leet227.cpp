/*
leet227


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


struct Op
{
    char name; int precedence;
};

unordered_map<char, Op> M = {
    {'(', {'(', 2}},
    {'*', {'*', 1}},
    {'/', {'/', 1}},
    {'+', {'+', 0}},
    {'-', {'-', 0}},
};
class Solution {
public:
    int calculate(string s) {
        // 中缀表达式 转 后缀表达式
        stack<Op> ops;
        stack<int> val;
        const auto n = s.size();

        auto pop = [&]() {
            auto top = ops.top(); ops.pop();
            auto b = val.top(); val.pop();
            auto a = val.top(); val.pop();
            int c;
            switch (top.name)
            {
            case '+': c = a + b; break;
            case '-': c = a - b; break;
            case '*': c = a * b; break;
            case '/': c = a / b; break;
            }
            val.push(c);
        };
        
        for (size_t i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case ' ':  break;
            case '(': case '+': case '-': case '*': case '/': {
                auto op = M[s[i]];
                while (ops.size() and op.precedence <= ops.top().precedence) pop();
                ops.push(op); break;
            }
            case ')': 
                while (ops.top().name != '(') pop(); break;

            default:
                int x = 0;
                while (i < n and isdigit(s[i])) {
                    x = x * 10 + (s[i] - '0');
                    i++;
                } i--;
                val.push(x);
                break;
            }
        }
        while (ops.size()) pop();
        return val.top();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.calculate("3+2*2") << endl;
    cout << sol.calculate(" 3/2 ") << endl;
    cout << sol.calculate(" 3+5 / 2 ") << endl;
    return 0;
}
