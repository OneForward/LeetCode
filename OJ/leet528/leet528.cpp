/*
leet528


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;


template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}



class Solution {
    vector<int> cdf;
public:
    Solution(vector<int>& w) {
        cdf = w;
        for (int i = 1; i < w.size(); ++i) { 
            cdf[i] += cdf[i-1];
        }
        // cout << cdf;
    }
    
    int pickIndex() {
        auto x = rand() % cdf.back();
        auto ans = upper_bound(cdf.begin(), cdf.end(), x);
        return ans-cdf.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */



int main(int argc, char const *argv[])
{
    vector<int> w = {1, 2, 3, 4};
    Solution sol(w);   

    vector<int> Counter(4, 0);
    for (int i = 0; i < 10000; ++i) { 
        Counter[sol.pickIndex()]++;
    }
    cout << Counter;

    return 0;
}



