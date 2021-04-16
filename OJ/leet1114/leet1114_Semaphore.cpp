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
#include <semaphore>
#include <future>
#include <atomic>

// #include "semaphore.h"
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

void printFirst() { cout << "First\n";  }
void printSecond() {  cout << "Second\n"; }
void printThird() {  cout << "Third\n"; }


class Foo {
public:
    binary_semaphore P1{0}, P2{0};

    Foo() { }

    void first(function<void()> printFirst) {
        
        printFirst();

        P1.release();
    }

    void second(function<void()> printSecond) {
        P1.acquire();

        printSecond();

        P2.release();
    }

    void third(function<void()> printThird) {
        P2.acquire();
        
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
