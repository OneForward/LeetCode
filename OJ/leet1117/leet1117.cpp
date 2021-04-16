/*
leet1117


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

void releaseHydrogen() { cout << "H"; }
void releaseOxygen() { cout << "O"; }

class H2O {
    mutex  mutex_O, mutex_H;
    condition_variable cv;
    int cntH = 0, cntO = 0;
public:
    H2O() { }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock Lock(mutex_H);
        cv.wait(Lock, [&]() { return cntH < 2; } );

        releaseHydrogen(); cntH++; 
        if (cntO == 1 and cntH == 2) cntO = 0, cntH = 0;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock Lock(mutex_O);
        cv.wait(Lock, [&]() { return cntO == 0; } );

        releaseOxygen(); cntO++; 
        if (cntO == 1 and cntH == 2) cntO = 0, cntH = 0;
        cv.notify_all();
    }
};

int main(int argc, char const *argv[])
{
    H2O h2o;
    vector<thread> Ts;
    for (int i = 0; i < 24; ++i) {
        if (i < 8)
            Ts.push_back(thread(&H2O::oxygen, &h2o, releaseOxygen));
        else 
            Ts.push_back(thread(&H2O::hydrogen, &h2o, releaseHydrogen)); 
    }
    for (auto&& t: Ts) t.join();
    return 0;
}
