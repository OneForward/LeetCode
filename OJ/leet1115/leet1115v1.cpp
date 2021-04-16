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
    bool foodone{};
public:
    FooBar(int n): n {n} {  }

    void foo(function<void()> printFoo) {
        
        unique_lock L{M};
        for (int i = 0; i < n; i++) {
            cv.wait(L, [&](){return !foodone; });
        	printFoo();
            foodone = true; cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        unique_lock L{M};
        for (int i = 0; i < n; i++) {
            cv.wait(L, [&](){return foodone; });
        	printBar();
            foodone = false; cv.notify_one(); 
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
