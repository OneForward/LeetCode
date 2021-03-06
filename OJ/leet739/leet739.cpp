/*
leet739


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> S;
        int n = T.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; --i) {
            while (S.size() and T[S.top()] <= T[i] ) S.pop();
            ans[i] =  S.size() ? S.top() - i : 0 ;
            S.push(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
