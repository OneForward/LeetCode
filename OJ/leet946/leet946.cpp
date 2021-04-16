/*
leet946


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
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> S; 
        int lft = 0, rht = 0, n = pushed.size();
        while (lft < n) {
            S.push(pushed[lft++]);
            while ( rht < n && !S.empty() && S.top() == popped[rht]) S.pop(), rht++;
        }
        return S.empty();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   

    cout << boolalpha << sol.validateStackSequences( {1,2,3,4,5}, {4,5,3,2,1}) << endl;
    cout << boolalpha << sol.validateStackSequences( {1, 0}, {1,0}) << endl;
    cout << boolalpha << sol.validateStackSequences( {1,2,3,4,5}, {4,3,5,1,2}) << endl;
    return 0;
}
