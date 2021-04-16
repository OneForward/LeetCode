#include <iostream>
using namespace std;

struct Pair {
    int index;
    int priority;

    Pair(int i=0, int p=0): index{i}, priority{p} {}
};

template <class T> struct Queue {
    T* data;
    int head, tail;
    int capacity;
    Queue(int size=127): data{new T[size]}, head{0}, tail{0}, capacity{size} {}

    void push(const T& val) {
        tail = (tail + 1) % capacity;
        data[tail] = val;
    }

    T pop() { 
        head = (head + 1) % capacity;
        return data[head];
    }
    
    bool isempty() {
        return head == tail;
    }

    void clear() { head = tail = 0; }

};


int main(int argc, char const *argv[])
{
    // freopen("case01.in", "r", stdin);
    int T, N, J, priority, time;
    Queue<Pair> Q(127);
    cin >> T;
    while (T--) {
        cin >> N >> J;
        int C[10]{}; time = 0;
        Q.clear();
        for (int i=0; i<N; ++i) cin >> priority, Q.push(Pair({i, priority})), C[priority] += 1;
        int cur_priority = 9;
        while (C[cur_priority] == 0) cur_priority--;
        while (!Q.isempty()) {
            
            Pair val = Q.pop();
            if (val.priority < cur_priority) Q.push(val);
            else if (val.index == J) { cout << ++time << endl; break; }
            else {
                time++;
                C[cur_priority]--;
                while (C[cur_priority] == 0) cur_priority--;
            }
        }        
    }
    return 0;
}
