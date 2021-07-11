/*
leet5809


*/

#include <bit>
#include "../utils/LeetCpp.utils.hpp"
using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

int count(unsigned x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int N = s.size();
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        for (int i = 0; i < N; i++)
        {
            auto pos = s[i] - 'a';
            if (start[pos] == -1) start[pos] = i;
            end[pos] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            unsigned cnt = 0;
            for (int j = start[i] + 1; j < end[i]; j++)
            {
                cnt |= 1 << (s[j] - 'a');
            }
            ans += count(cnt);
            // ans += popcount(cnt);
        }
        
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countPalindromicSubsequence("aabca") << endl;
    cout << sol.countPalindromicSubsequence("adc") << endl;
    cout << sol.countPalindromicSubsequence("bbcbaba") << endl;
    return 0;
}
