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
    unique_lock<mutex> L1, L2;

    Foo(): L1{P12, try_to_lock}, L2{P23, try_to_lock} { }

    void first(function<void()> printFirst) {
        printFirst();
        L1.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard guard(P12);
        printSecond();
        L2.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard guard(P23);
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
