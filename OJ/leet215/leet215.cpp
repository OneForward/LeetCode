/*
leet215


*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int findKthLargest1(const vector<int>& nums, int k) {
        // 24ms
        priority_queue<int> Q(nums.begin(), nums.end());
        while (--k) Q.pop();
        return Q.top();
    }
    int findKthLargest(const vector<int>& nums, int k) {
        // 36ms
        priority_queue<int, vector<int>, greater<int>> Q;
        for (int i = 0; i < k; ++i) Q.push(nums[i]);
        for (int i = k; i < nums.size(); ++i)  Q.push(nums[i]), Q.pop();
        return Q.top();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findKthLargest( {3,2,1,5,6,4}, 2) << endl;
    cout << sol.findKthLargest( {3,2,3,1,2,4,5,5,6}, 4) << endl;
    return 0;
}
