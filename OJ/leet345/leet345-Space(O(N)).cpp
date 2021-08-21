/*
leet345


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string reverseVowels(string s) {

        auto f = vector<int>{};
        const string VOEWL = "aeiou";
        for (size_t i = 0; i < s.size(); i++)
        {
            for (auto&& vowel: VOEWL) {
                if (tolower(s[i]) == vowel) {
                    f.push_back(i);
                }
            }
        }

        auto len = f.size();
        for (size_t i = 0; i < len / 2; i++)
        {
            swap(s[f[i]], s[f[len-i-1]]);
        }

        return s;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.reverseVowels("hello") << endl;
    cout << sol.reverseVowels("leetcode") << endl;
    return 0;
}
