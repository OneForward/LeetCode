/*
leet008


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int start = 0, n = s.size();
        while (start < n and s[start] == ' ') start++;
        if (start == n) return 0;

        long long sign = 1, ans = 0;
        switch (s[start])
        {
        case '+': start++; break;
        case '-': start++; sign = -1; break;
        default : if (not isdigit(s[start])) return 0;
        }

        for (int i = start; i < n and isdigit(s[i]); i++)
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX) return sign > 0 ? INT_MAX : INT_MIN;
        }
        return sign * ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.myAtoi("       -12999") << endl;
    cout << sol.myAtoi("words and 987") << endl;
    cout << sol.myAtoi("4193 with words") << endl;
    cout << sol.myAtoi("-91283472332") << endl;
    return 0;
}
