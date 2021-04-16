/*
leet060


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
    string getPermutation(int n, int k) {
        // 4ms
        vector<char> L, ans;
        for (int i = 1; i <= n; ++i) L.push_back(i + '0');
        
        int f = 1, pos;
        for (int i = 2; i < n; ++i) f *= i;
        
        k -= 1;
        for (int i = n-1; i > 0; --i) {
            pos = k / f;
            ans.push_back(L[pos]);
            L.erase(L.begin() + pos);
            k -= pos * f; 
            f /= i;   
        }
        ans.push_back(L[0]);
        return string(ans.begin(), ans.end());
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.getPermutation(1, 1) << endl;

    return 0;
}
