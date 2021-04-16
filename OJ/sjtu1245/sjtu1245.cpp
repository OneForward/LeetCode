/*
stack, Token
中缀表达式转前缀表达式，并计算前缀表达式的值
*/


#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

template <class T>
struct Node {
    T val;
    Node* next;
    Node(const T& v=T(), Node* n=nullptr): val(v), next(n) {}
};

template <class T>
struct Stack
{
    Node<T>* head;
    Stack() : head(nullptr) {}
    void push(const T& x) {
        head = new Node<T>(x, head);
    }

    T front() { return head->val; }
    T pop() {
        T val = head->val;
        Node<T>* tmpNode = head;
        head = head->next;
        delete tmpNode;
        return val;
    }

    bool isempty() { return head == nullptr; }
};

enum TYPE {
    INIT, NUMBER, OPERATOR, CPAREN, OPAREN
};

struct Token
{
    int type;
    int val;
    Token(int t=0, int v=0):type(t), val(v) {}

    friend ostream& operator<<(ostream& os, const Token& t) {
        switch (t.type) {
            case NUMBER: os << t.val << " "; return os;
            default    : os << (char)t.val << " "; return os;
        }
    }
};

const int MAX_N = 1005;
char infix[MAX_N];
int in_size = 0;
Stack<Token> opStack, rstStack, prefixStack;
Stack<int> ansStack;
int P[256] = {};

bool isdigit(const char& ch) { return '0' <= ch and ch <= '9'; }

Token next_token(char str[], int& rht) { // from right

    while (rht >= 0 and str[rht] == ' ') rht--;
    if (rht == -1) { rht--; return Token(INIT, '#'); }
    
    if (isdigit(str[rht])) {
        int val = 0, weight = 1;
        do { val += (str[rht--]-'0')*weight, weight *= 10; } while (isdigit(str[rht]));
        return Token(NUMBER, val);
    }
    
    switch (str[rht--]) {
        case '+': return Token(OPERATOR, '+');
        case '-': return Token(OPERATOR, '-');
        case '*': return Token(OPERATOR, '*');
        case '/': return Token(OPERATOR, '/');
        case '(': return Token(OPAREN, '(');
        case ')': return Token(CPAREN, ')');       
    }
}

void infix_to_prefix() {
    P['('] = P[')'] = 0;
    P['+'] = P['-'] = 10;
    P['*'] = P['/'] = 100;

    int in_p = in_size - 2;
    Token token;
    while (in_p >= -1) {
        token = next_token(infix, in_p); 
        switch (token.type) {
            case NUMBER: rstStack.push(token); break;
            case CPAREN: opStack.push(token); break;
            case OPERATOR:
                while (not opStack.isempty() and P[token.val] < P[opStack.front().val])
                    rstStack.push(opStack.pop());
                opStack.push(token); break;
            case OPAREN:
                while (opStack.front().type != CPAREN) rstStack.push(opStack.pop());
                opStack.pop(); break;
            case INIT:
                while (not opStack.isempty()) rstStack.push(opStack.pop());
        }
    }

    while (not rstStack.isempty()) {
        token = rstStack.pop();
        prefixStack.push(token);
        switch (token.type) {
            case NUMBER: cout << token.val; break;
            default: cout << (char)token.val;
        }
        if (not rstStack.isempty()) cout << ' ';
    }
    
    cout << endl;
}

void calc_prefix() {
    Token token;
    int p1, p2;
    while (not prefixStack.isempty()) {
        token = prefixStack.pop();
        switch (token.type) {
            case NUMBER: ansStack.push(token.val); break;
            default:
                p1 = ansStack.pop(), p2 = ansStack.pop();
                switch (token.val) {
                    case '+': ansStack.push(p1 + p2); break;
                    case '-': ansStack.push(p1 - p2); break;
                    case '*': ansStack.push(p1 * p2); break;
                    case '/': ansStack.push(p1 / p2); break;
                }
        }
    }
    cout << ansStack.pop();
}


int main(int argc, char const *argv[])
{
    while (scanf("%c", &infix[in_size++]) != EOF);

    infix_to_prefix();
    
    calc_prefix();

    return 0;
}
