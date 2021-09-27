/*
leet639


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

using LL=long long;
const LL MOD = 1e9 + 7;
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;

        LL f[100005]{1, 1};
        int N = s.size();
        
        for (int i = 0; i < N; i++)
        {
            auto rht = s[i];
            auto lft = (i >= 1 ? s[i-1] : 0);
            
            int k = 0;
            if (rht == '*') k = 9;
            else if (rht != '0') k = 1;
            else k = 0;

            f[i+2] += k * f[i+1];
            

            k = 0;
            if (lft == '*') {
                if (rht == '*') k = 15;
                else if ('0' <= rht and rht <= '6') k = 2;
                else k = 1;
            }
            else if (lft == '1') {
                if (rht == '*') k = 9;
                else k = 1;
            }
            else if (lft == '2') {
                if (rht == '*') k = 6;
                else if ('0' <= rht and rht <= '6') k = 1;
                else k = 0;
            }

            f[i+2] += k * f[i];
            f[i+2] %= MOD;
        }
        return f[N+1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numDecodings("*") << endl;
    cout << sol.numDecodings("1*") << endl;
    cout << sol.numDecodings("2*") << endl;
    cout << sol.numDecodings("*1*1*0") << endl;
    return 0;
}
