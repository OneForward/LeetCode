/*
leet084


*/


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:

    int largestRectangleArea(const vector<int>& v) {
        // 24ms, 单调栈
        if (v.empty()) return 0;
        int ans = 0, n = v.size(), Stop;
        vector<int> lft(n), rht(n); stack<int> S; 
        
        S = {};
        for (int i = 0; i < n; ++i) {
            while (!S.empty() && v[S.top()] >= v[i])  S.pop();
            lft[i] = S.empty() ? -1 : S.top() ;
            S.push(i); 
        }
        S = {}; 
        for (int i = n-1; i >= 0; --i) {
            while (!S.empty() && v[S.top()] >= v[i])  S.pop();
            rht[i] = S.empty() ? n : S.top() ;
            S.push(i); 
        }
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, v[i] * (rht[i] - lft[i] - 1) );
        }
        
        return ans;
    }
};

class Solution1 {
public:
    int largestRectangleArea(vector<int>& A, int i, int j)  {
        // Average O(n log n), Worst O(N^2) , 1324 ms
        // 考虑 线段树O(log n) 查找最小数位置，则复杂度可降为 O(n)
        if (i >= j) return 0;
        int mlft = i;
        for (int k = i + 1; k < j; ++k) {
            if (A[k] < A[mlft]) mlft = k;
        }

        int mrht = mlft+1;
        while (mrht < j && A[mlft] == A[mrht]) mrht++;
        
        int S = A[mlft] * (j - i);

        int Slft = largestRectangleArea(A, i, mlft);
        int Srht = largestRectangleArea(A, mrht, j);
        return max(max(Slft, Srht), S);
    }
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleArea(heights, 0, heights.size());
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;   

    cout << sol.largestRectangleArea({ 1 ,1, 1, 1,1 }) << endl;
    cout << sol.largestRectangleArea({  2,1,5,6,2,3 }) << endl;
    cout << sol.largestRectangleArea({ 9, 0 }) << endl;
    cout << sol.largestRectangleArea({ 2,3 }) << endl;
    return 0;
}
