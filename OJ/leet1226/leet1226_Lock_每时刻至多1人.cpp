/*
leet1226


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

void pickLeftFork() {  } 
void pickRightFork() {  } 
void eat() {  } 
void putLeftFork() {  } 
void putRightFork() {  } 



class DiningPhilosophers {
public:
    // int cnt[5]{};
    mutex M;

    DiningPhilosophers() { }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        lock_guard L(M);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

};

int main(int argc, char const *argv[])
{
    DiningPhilosophers sol;
    vector Philosophers = {
        new thread(&DiningPhilosophers::wantsToEat, &sol, 0, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork),
        new thread(&DiningPhilosophers::wantsToEat, &sol, 1, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork),
        new thread(&DiningPhilosophers::wantsToEat, &sol, 2, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork),
        new thread(&DiningPhilosophers::wantsToEat, &sol, 3, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork),
        new thread(&DiningPhilosophers::wantsToEat, &sol, 4, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork),
    };
    
    int n = 1;
    for (int i = 0; i < 5 * n; ++i) {
        for (auto&& t: Philosophers) t->join();
    }
    return 0;
}
