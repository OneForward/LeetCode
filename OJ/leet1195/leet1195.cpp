/*
leet1195


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

void printFizz() { cout << "fizz, "; }
void printBuzz() { cout << "buzz, "; }
void printFizzBuzz() { cout << "fizzbuzz, "; }
void printNumber(int x) { cout << x << ", "; }

class FizzBuzz {
private:
    int n;
    int cnt = 1;
    condition_variable cv;
    mutex M;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock Lock(M);
            cv.wait(Lock, [&]() { return (cnt % 3 == 0 and cnt % 5) or cnt > n; } );
            if (cnt > n) break;

            printFizz(); cnt++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock Lock(M);
            cv.wait(Lock, [&]() { return (cnt % 5 == 0 and cnt % 3 )or cnt > n; } );
            if (cnt > n) break;

            printBuzz(); cnt++;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock Lock(M);
            cv.wait(Lock, [&]() { return (cnt % 3 == 0 and cnt % 5 == 0) or cnt > n; } );
            if (cnt > n) break;

            printFizzBuzz(); cnt++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock Lock(M);
            cv.wait(Lock, [&]() { return (cnt % 3 and cnt % 5) or cnt > n; } );
            if (cnt > n) break;

            printNumber(cnt); cnt++;
            cv.notify_all();
        }
    }
};


int main(int argc, char const *argv[])
{
    FizzBuzz obj{100};
    vector v = {
        new thread(&FizzBuzz::fizz, &obj, printFizz),
        new thread(&FizzBuzz::buzz, &obj, printBuzz),
        new thread(&FizzBuzz::fizzbuzz, &obj, printFizzBuzz),
        new thread(&FizzBuzz::number, &obj, printNumber),
    };
    for (auto&& t: v) t->join();
    return 0;
}
