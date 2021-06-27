/*
leet1363


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int> A) {
        int f[10]{}; auto sum = 0;
        for (auto &&x : A) f[x]++, sum += x;
        
        auto div = sum % 3;
        if (div == 0) goto end;

        // try remove only 1 digit
        while (div < 10 and f[div] == 0) div += 3;
        if (div < 10) {f[div]--; goto end; };

        // try remove 2 digit
        div = sum % 3;
        for (int i = 0; i < 10; i++)
        {
            if (f[i] >= 2 and 2 * i % 3 == div) {
                f[i] -= 2; goto end;
            }
            for (int j = i + 1; j < 10; j++)
            {
                if (f[i] and f[j] and (i + j) % 3 == div) {
                    f[i]--; f[j]--; goto end;
                }
            }
            
        }
        return {};
        
        end:
        string s;
        for (int i = 10 - 1; i > 0; i--)
            if (f[i]) s += string(f[i], i + '0');
        if (s.empty() and f[0]) return "0";
        return s + string(f[0], '0');
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    // cout << sol.largestMultipleOfThree({8,1,9}) << endl;
    // cout << sol.largestMultipleOfThree({8,6,7,1,0}) << endl;
    cout << sol.largestMultipleOfThree({1}) << endl;
    cout << sol.largestMultipleOfThree({0,0,0,0,0,0}) << endl;
    return 0;
}
