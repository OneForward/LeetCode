/*
leet703


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
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> Q;
    int k;
    KthLargest(int _k, const vector<int>& nums):k(_k) {
        for (const auto& x: nums) {
            if (Q.size() == k) {
                if (x >= Q.top())  Q.pop(), Q.push(x);
            }
            else Q.push(x);
        }
    }
    
    int add(int x) {
        if (Q.size() == k) {
            if (x >= Q.top())  Q.pop(), Q.push(x);
        }
        else Q.push(x);
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char const *argv[])
{
    KthLargest obj(3, {4,5,8,2});
    cout << obj.add(3) << endl;
    cout << obj.add(5) << endl;
    cout << obj.add(10) << endl;
    cout << obj.add(9) << endl;
    cout << obj.add(4) << endl;
    return 0;
}
