/*
leet528


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

class Solution {
    VI cdf;
public:
    Solution(vector<int>& w) {
        cdf = w;
        for (size_t i = 1; i < w.size(); ++i) { 
            cdf[i] += cdf[i-1];
        }
    }
    
    int pickIndex() {
        auto x = rand() % cdf.back();
        auto ans = upper_bound(ALL(cdf), x) - cdf.begin();
        return ans;
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



