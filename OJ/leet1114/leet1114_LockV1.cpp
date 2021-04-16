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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

void printFirst() { cout << "First\n";  }
void printSecond() {  cout << "Second\n"; }
void printThird() {  cout << "Third\n"; }


class Foo {
public:
    mutex P12, P23;
    Foo() {
        P12.lock(), P23.lock();
    }

    void first(function<void()> printFirst) {
        
        printFirst();
        P12.unlock();
    }

    void second(function<void()> printSecond) {
        P12.lock();
        printSecond();
        P23.unlock();
    }

    void third(function<void()> printThird) {
        P23.lock();
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
