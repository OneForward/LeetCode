/*
sjtu1605

括号栈：提供 全部 O(1) 的 push, pop, top, query(是否为合法括号栈)
*/


#include <iostream>

using namespace std;

bool isRight(char ch) {
    return ch == ')' or ch == ']' or ch == '}';
}

bool isMatch(char lft, char rht) {
    return (lft == '(' and rht == ')') or
           (lft == '[' and rht == ']') or
           (lft == '{' and rht == '}') ;
}

char reMatch(char ch) {
    switch (ch)
    {
    case ')': return '(';
    case ']': return '[';
    default : return '{';
    }
}

const int N = 2e6 + 5;
struct Stack
{
    char data[N];
    int len{};

    void push(char x) { data[len++] = x; }

    void pop() { len--; } 

    char top() const { return data[len-1]; }

    bool empty() const { return len == 0; }

    int size() const { return len; }
};

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    Stack S1, S2;

    int n, op; char ch;
    cin >> n;
    while (n--) {
        cin >> op;
        switch (op) {
            case 1: cin >> ch;  
                    if (isRight(ch) and S2.size() and isMatch(S2.top(), ch)) S1.push('#'),  S1.push(ch), S2.pop();
                    else  S1.push(ch), S2.push(ch);
                break;
            case 2: if (S1.size()) {
                    ch = S1.top(); S1.pop();
                    if (isRight(ch) and S1.size() and S1.top() == '#') S1.pop(), S2.push(reMatch(ch));
                    else S2.pop();
                }
                break;
            case 3:  if (S1.size()) cout << S1.top()  << '\n'; break;
            case 4:  cout << (S2.empty() ? "YES\n" : "NO\n");
        }
    }
    
    return 0;
}
