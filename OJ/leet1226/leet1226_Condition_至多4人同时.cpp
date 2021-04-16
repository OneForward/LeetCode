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
    mutex M[5]{}, cv_mutex;
    condition_variable cv;
    
    int cnt = 0;
    DiningPhilosophers() { }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        unique_lock Lock(cv_mutex);
        cv.wait(Lock, [&](){ return cnt < 5; });
        cnt++; cv.notify_all();
        int lft = philosopher, rht = (philosopher + 1) % 5;
        
        M[lft].lock();
        pickLeftFork();

        M[rht].lock();
        pickRightFork();

        eat();

        putLeftFork(); M[lft].unlock();
        putRightFork(); M[rht].unlock();
        cnt--; cv.notify_all();
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
