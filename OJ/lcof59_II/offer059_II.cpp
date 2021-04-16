/*
offer059_II


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
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;


class MaxQueue {
public:
    vector<int> Q;
    int start, end;
    deque<int> M;
    int SIZE;

    MaxQueue():SIZE(10005), Q(10005), M(10005) {
        start = end = 0;
    }
    
    int max_value() {
        return start == end ? -1 : M[0];
    }

    void push_back(int value) {
        Q[end] = value;
        while (!M.empty() and M.back() < value) M.pop_back();
        M.push_back(value);
        end = (end + 1) % SIZE;
    }
    
    int pop_front() {
        if (start == end) return -1;
        int val = Q[start];
        if (!M.empty() and val == M[0]) M.pop_front();
        start = (start + 1) % SIZE;
        return val;
    }
};

int main(int argc, char const *argv[])
{
    MaxQueue Q;
    cout << Q.max_value() << endl;
    Q.push_back(1);
    Q.push_back(2);
    cout << Q.max_value() << endl;
    cout << Q.pop_front() << endl;
    cout << Q.max_value() << endl;

    return 0;
}
