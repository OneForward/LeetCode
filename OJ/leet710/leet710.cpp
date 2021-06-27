/*
leet710


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    unordered_map<int, int> M;
    int len;
    
    Solution(int N, const vector<int>& B) {
        auto blen = B.size();
        len = N - blen;
        unordered_set<int> Bset;
        for (int i = len; i < N; i++) Bset.insert(i);
        for (auto &&x : B) if (x >= len) Bset.erase(x);
        
        auto p = Bset.begin();
        for (auto &&x : B) if (x < len) M[x] = *p++;
    }
    
    int pick() {
        auto x = rand() % len;
        return M.find(x) == M.end() ? x : M[x];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
