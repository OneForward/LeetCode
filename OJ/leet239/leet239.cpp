/*
leet239


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& A, int k) {
        // # 双端队列法
        // # 本质是维护一个严格单调递减的双端队列, 同时保存顺序信息和最值信息
        deque<int> Q(k); vector<int> ans;
        for (int i = 0; i < k; ++i) { 
            while (!Q.empty() && A[i] >= A[Q.back()]) Q.pop_back();
            Q.push_back(i);
        }
        ans.push_back(A[Q[0]]);

        for (int i = k; i < A.size(); ++i) { 
            if (Q[0] + k <= i) Q.pop_front();
            while (!Q.empty() && A[i] >= A[Q.back()]) Q.pop_back();
            Q.push_back(i);
            ans.push_back(A[Q[0]]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << endl;
    cout << sol.maxSlidingWindow({1}, 1) << endl; 
    cout << sol.maxSlidingWindow({1, -1}, 1) << endl; 
    cout << sol.maxSlidingWindow({1,3,1,2,0,5}, 3) << endl; 
    return 0;
}
