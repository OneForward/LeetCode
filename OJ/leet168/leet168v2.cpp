/*
leet168


*/


#include <iostream>
#include <vector>
#include <queue>
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
    string convertToTitle(int n) {
        // 0ms
        vector<char> v; 
        do {
            v.push_back((n-1) % 26 + 'A'); n = (n-1) / 26;
        } while (n);
        return string(v.rbegin(), v.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.convertToTitle(28) << endl;
    for (int n = 1; n < 55; ++n)
        cout << n << ": " << sol.convertToTitle(n) << endl;
    return 0;
}
