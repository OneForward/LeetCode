/*
leet480


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
#include "../utils/LeetCpp.utils.hpp"


class Solution {
public:

    vector<double> medianSlidingWindow(const vector<int>& A, const int k) {
        // 对顶堆, 44ms, 15MB
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        unordered_map<int, int> M;
        vector<double> ans;
        
        for (int i = 0; i < k; ++i) minQ.push(A[i]);
        for (int i = 0; i < k/2; ++i) maxQ.push(minQ.top()), minQ.pop();
        
        auto get = [&]() -> double {
            if (k % 2) return minQ.top();
            return (minQ.top() + (double)maxQ.top()) / 2.;
        };

        ans.push_back(get());

        for (int i = k; i < A.size(); ++i) { 
            int balance = 0; M[A[i-k]]++;
            
            if (not minQ.empty() and A[i-k] >= minQ.top())  balance--; 
            else balance++;

            if (A[i] <= minQ.top()) {
                maxQ.push(A[i]); balance--;
            }
            else {
                minQ.push(A[i]); balance++;
            }
            
            
            if (balance == 2) {
                maxQ.push(minQ.top()), minQ.pop();
            }
            if (balance == -2) {
                minQ.push(maxQ.top()), maxQ.pop();
            }

            while (!minQ.empty() and M[minQ.top()] > 0) {
                M[minQ.top()]--; minQ.pop(); 
            }
            while (!maxQ.empty() and M[maxQ.top()] > 0) {
                M[maxQ.top()]--; maxQ.pop(); 
            }


            ans.push_back(get());
        }


        return ans;
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.medianSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << endl;
    cout << sol.medianSlidingWindow({1,2,3,4,2,3,1,4,2}, 3) << endl;
    cout << sol.medianSlidingWindow({2,2}, 2) << endl;
    return 0;
}
