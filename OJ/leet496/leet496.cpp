/*
leet496


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


struct MonoStack2
{
    vector<int> v;

    void push(int x) {
        while (v.size() and v.back() <= x) v.pop_back();
        v.push_back(x);
    }

    int query(int x) {
        auto pos = upper_bound(v.rbegin(), v.rend(), x);
        return pos == v.rend() ? -1 : *pos;
    }
};

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
    vector<int> nextGreaterElement(const vector<int>& A, const vector<int>& B) {
        // O(N+M)
        int n = A.size(), m = B.size();
        MonoStack S;
        unordered_map<int, int> M;
        for (int i = m-1; i >= 0; i--)
        {
            auto x = B[i];
            M[x] = S.query(x);
            S.push(x);
        }

        vector<int> ans(n);
        for (size_t i = 0; i < n; i++)
        {
            ans[i] = M[A[i]];
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.nextGreaterElement({4,1,2}, {1,3,4,2}) << endl;
    cout << sol.nextGreaterElement({2,4}, {1,2, 3,4,}) << endl;
    return 0;
}
