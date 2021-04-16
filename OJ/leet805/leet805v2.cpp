/*
leet805


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
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    
    vector<int>  f(vector<int> A) {
        int n = A.size();
        vector<int> f(1<<n);
        for (size_t x = 0; x < n; x++)
            f[1<<x] = A[x] ;
        
        for (size_t x = 1; x < (1<<n); x++)
            f[x] = f[x & -x] + f[x & (x-1)];
        return vector<int>(f.begin()+1, f.end());
    }
    bool splitArraySameAverage( vector<int> A) {
        int n = A.size(), total = reduce(A.begin(), A.end(), 0);
        for (auto &&x : A) x = x * n - total;
        
        if (n <= 1) return false;

        vector<int> Alft(A.begin(), A.begin() + n/2);
        vector<int> Arht(A.begin()+n/2, A.begin() + n);
        auto flft = f(Alft);
        auto frht = f(Arht);
        
        unordered_set<int> Mlft, Mrht;
        for (auto && x : flft) Mlft.insert(x);
        for (auto && x : frht) Mrht.insert(x);
        
        if (Mlft.find(0) != Mlft.end()) return true;
        if (Mrht.find(0) != Mrht.end()) return true;
        
        auto sumlft = reduce(Alft.begin(), Alft.end(), 0);  
        for (auto &&x : Mlft)
        {
            if (x != sumlft and Mrht.find(-x) != Mrht.end()) 
                return true;
        }
        
        return false;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.splitArraySameAverage({6,8,18,3,1}) << endl;
    // cout << sol.splitArraySameAverage({10,29,13,53,33,48,76,70,5,5}) << endl;
    // cout << sol.splitArraySameAverage({3,1}) << endl;
    // cout << sol.splitArraySameAverage({18,10,5,3}) << endl;
    // cout << sol.splitArraySameAverage({1,2,3,4,5,6,7,8}) << endl;
    // cout << sol.splitArraySameAverage({0}) << endl;
    
    return 0;
}
