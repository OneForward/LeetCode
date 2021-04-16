/*
leet1115


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
#include <mutex>
#include <condition_variable>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

void printFoo() { cout << "Foo"; }
void printBar() { cout << "Bar"; }

class FooBar {
private:
    int n;
    condition_variable cv;
    mutex M;
    int cnt = 0;
public:
    FooBar(int n): n {n} {  }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock L{M};
            cv.wait(L, [&](){return cnt == 2 * i; });
        	printFoo();
            cnt++; cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock L{M};
            cv.wait(L, [&](){return cnt == 2 * i + 1; });
        	printBar();
            cnt++; cv.notify_all(); 
        }
    }
};

int main(int argc, char const *argv[])
{
    FooBar foo{5};
    auto t1 = thread(&FooBar::foo, &foo, printFoo);
    auto t2 = thread(&FooBar::bar, &foo, printBar);
    t2.join(); t1.join(); 
    return 0;
}
