/*
最小数栈：提供O(1)时间复杂度的push，pop，top，getMin操作
*/


#include <iostream>

using namespace std;

const int N = 1e6 + 5;
template <class T>
struct Stack
{
    T* data;
    int len;

    Stack(): data{new T[N]}, len{} {}

    void push(T x) { data[len++] = x; }

    void pop() { len--; } 

    T top() const { return data[len-1]; }

    bool empty() const { return len == 0; }

    int size() const { return len; }
};

int main( )
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    Stack<unsigned> S1, S2;

    unsigned n, op, x;
    cin >> n;
    while (n--) {
        cin >> op;
        switch (op) {
            case 0: cin >> x;  S1.push(x); 
                if (S2.empty() or S2.top() >= x) S2.push(x);
                break;
            case 1: if (S1.size()) {
                x = S1.top(); S1.pop();
                if (S2.top() == x) S2.pop();
            }
            else cout << "Empty\n";
            break;
            case 2:  
            if (S1.size()) cout << S1.top()  << '\n'; else cout << "Empty\n"; break;
            case 3:  
            if (S2.size()) cout << S2.top()  << '\n'; else cout << "Empty\n";
        }
    }
    return 0;
}
