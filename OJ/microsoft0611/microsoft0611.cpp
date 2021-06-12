/*
microsoft0611


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

// 整型数组
// 乘积最大的子数组

int solution(const vector<int>& v) {
    // max product of subarray
    // f(i) : max abs product up to i 
    // f(i) = max(abs(Ai), abs(f(i-1) * Ai))? 
    // Time O(N) Space O(1)
    
    int ans = INT_MIN, pos = 1, neg = 1;
    for (auto&& x: v) {
        auto oldpos = pos, oldneg = neg;
        pos = max({x, oldpos * x, oldneg * x});
        neg = min({x, oldpos * x, oldneg * x});
        ans = max(ans, pos);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    cout << solution({-1, -5, 1, 2, 4}) << endl;
    cout << solution({-1, -5, 1, }) << endl;
    cout << solution({-1, -5, 1, -1}) << endl;
    cout << solution({-1, -5, -1, -1}) << endl;
    cout << solution({-1, -5, 0, -1, -1}) << endl;
    cout << solution({1, 1, -5, 0, -1, -1}) << endl;
    return 0;
}
