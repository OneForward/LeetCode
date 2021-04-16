/*
leet503


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
#include "../utils/LeetCpp.utils.hpp"

using namespace std;


struct MonoStack
{
    stack<int> S;

    void push(int x) {
        while (S.size() and S.top() <= x) S.pop();
        S.push(x);
    }

    int query(int x) {
        while (S.size() and S.top() <= x) S.pop();
        return S.empty() ? -1 : S.top();
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>& A) {

        MonoStack S;
        int n = A.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            auto x = A[i];
            ans[i] = S.query(x); S.push(x);
        }
        for (int i = n - 1; i >= 0; --i) {
            auto x = A[i];
            if (ans[i] == -1) ans[i] = S.query(x); 
            S.push(x);
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.nextGreaterElements({1,2,1}) << endl;
    return 0;
}
