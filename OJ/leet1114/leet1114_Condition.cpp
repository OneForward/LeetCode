/*
leet1114


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

void printFirst() { cout << "First\n";  }
void printSecond() {  cout << "Second\n"; }
void printThird() {  cout << "Third\n"; }


class Foo {
public:
    condition_variable cv;
    mutex mx;
    int k = 0;
    
    Foo() { }

    void first(function<void()> printFirst) {
        
        printFirst();

        k = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        unique_lock Lock(mx);
        cv.wait(Lock, [&](){ return k == 1; } );

        printSecond();

        k = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        unique_lock Lock(mx);
        cv.wait(Lock, [&](){ return k == 2; } );

        printThird();
        
    }
};


int main(int argc, char const *argv[])
{
    Foo foo;
    thread t1(&Foo::first, &foo, printFirst);
    thread t2(&Foo::second, &foo, printSecond);
    thread t3(&Foo::third, &foo, printThird);
    t3.join();
    t2.join();
    t1.join();
    return 0;
}
