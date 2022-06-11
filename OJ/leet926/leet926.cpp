/*
leet926


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



// if ch == 0
// f(n+1, 1) = min( f1, f0 ) + 1;
// f(n+1, 0) = f0

// if ch == 1
// f(n+1, 1) = min( f1, f0 );
// f(n+1, 0) = f0 + 1


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        auto f1 = 0, f0 = 0;
        for (auto&& ch: s) {
            if (ch == '0') f1 = min(f1, f0) + 1;
            else           f1 = min(f1, f0), f0++;
        }
        return min(f1, f0);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
