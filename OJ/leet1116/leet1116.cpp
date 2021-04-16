/*
leet1116


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
#include <thread>
#include <condition_variable>
#include <mutex>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

void printNumber(int x) { cout << x; }

class ZeroEvenOdd {
private:
    int n;
    int cnt = 1;
    condition_variable cv;
    mutex M;
    bool zero_ok = true;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock Lock{M};
        for (int i = 0; i < n; ++i) {
            cv.wait(Lock, [&](){ return zero_ok; });
            printNumber(0);
            zero_ok = false; cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock Lock{M};
        for (int i = 0; i < n/2; ++i) {
            cv.wait(Lock, [&](){ return not zero_ok and cnt % 2 == 0; });
            printNumber(cnt);
            zero_ok = true; cnt++; cv.notify_all();
        }
        
    }

    void odd(function<void(int)> printNumber) {
        unique_lock Lock{M};
        for (int i = 0; i < (n+1)/2; ++i) {
            cv.wait(Lock, [&](){ return not zero_ok and cnt % 2 == 1; });
            printNumber(cnt);
            zero_ok = true; cnt++; cv.notify_all();
        }
    }
};


int main(int argc, char const *argv[])
{
    ZeroEvenOdd obj{11};   
    
    auto t0 = thread(&ZeroEvenOdd::zero, &obj, printNumber);
    auto t1 = thread(&ZeroEvenOdd::odd, &obj, printNumber);
    auto t2 = thread(&ZeroEvenOdd::even, &obj, printNumber);
    t2.join(); t1.join();  t0.join();
    return 0;
}
