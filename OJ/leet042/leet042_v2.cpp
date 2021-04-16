/*
leet042


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;



class Solution {
public:
    int trap(vector<int>& v) {
        // 12ms, 模拟方法, O(N)
        if (v.size() == 0) return 0;
        int p1 = 0, p2; int S = 0;
        while (p1 < v.size()-1 && v[p1] <= v[p1+1]) p1++; p2 = p1+1;
        while (p2 < v.size()-1) {
            int cur_max = p2;
            while (p2 < v.size()-1 && v[p2] < v[p1]) {
                p2++;
                if (v[p2] > v[cur_max]) cur_max = p2;
            }
            while (p2 < v.size()-1 && v[p2] <= v[p2+1]) p2++; 
            
            if (v[p2] < v[p1])  p2 = cur_max;
            
            int h = min(v[p1], v[p2]);
            for (int i = p1+1; i < p2; ++i) {
                if (h > v[i]) S += h - v[i];
            }
            p1 = p2; p2 = p1+1;
        }
        return S;
    }
};


int main(int argc, char const *argv[])
{
    // vector<int> v = {5, 2, 1, 2, 1, 5};
    // vector<int> v = {2,8,5,5,6,1,7,4,5};
    // vector<int> v = {5,5,1,7,1,1,5,2,7,6};
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution sol;
    cout << sol.trap(v) << endl;

    return 0;
}
