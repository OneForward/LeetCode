/*
leet031


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
    bool nextPermutation1(vector<int>& vec) {
        int N = vec.size(), p = N - 1;
        while (p >= 1 && vec[p-1] >= vec[p]) --p; 
        if (p >= 1) {
            int q = p;
            while (q < N && vec[p-1] < vec[q]) ++q;
            swap(vec[p-1], vec[q-1]);
        }
        for (int j = 0; j < (N-p)/2; ++j) 
            swap( vec[p+j], vec[N-1-j] );
            
        return p != 0;
    }
    void nextPermutation(vector<int>& vec) {
        // 12ms, 25%
        int N = vec.size(), p = N - 1;
        while (p >= 1 && vec[p-1] >= vec[p]) --p; 

        
        if (p >= 1) {
            int q = p;
            while (q < N && vec[p-1] < vec[q]) ++q;
            swap(vec[p-1], vec[q-1]);
        }
        for (int j = 0; j < (N-p)/2; ++j) 
            swap( vec[p+j], vec[N-1-j] );
    }
};

int main(int argc, char const *argv[])
{
    
    vector v = {1, 1, 2, 3, 5, 5};
    Solution sol; 
    // sol.nextPermutation(v);
    while (sol.nextPermutation1(v)) {
        for (auto vi: v) cout << vi << ", "; cout << endl;
    }
    for (auto vi: v) cout << vi << ", "; cout << endl;
    return 0;
}
