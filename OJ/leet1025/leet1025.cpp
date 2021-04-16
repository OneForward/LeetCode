/*
leet1025


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

class Solution {
public:
    bool divisorGame1(int N) {
        if (N < 2) return false;
        
        vector<bool> f(N+1);
        f[2] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j < i; ++j) { 
                if (i % j == 0 && f[i-j] == false) { 
                    f[i] = true; 
                    break;
                }
            }
        }
        return f[N];
    }
    bool divisorGame(int N) {
        return N % 2;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    for (auto x: {1,2,3,4,5,6,7,8,9,10}) {
        cout << x << ": " << boolalpha << sol.divisorGame(x) << endl;
    }
    return 0;
}
