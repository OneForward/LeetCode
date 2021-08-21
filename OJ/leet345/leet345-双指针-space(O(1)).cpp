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

        const string VOEWL = "AEIOUaeiou";
        auto isVowel = [&](char ch) {
            return VOEWL.find(ch) != VOEWL.npos;
        };

        int i =0, j = s.size() - 1;
        while (i < j)  {
            while (i < j and not isVowel(s[i])) i++;
            while (i < j and not isVowel(s[j])) j--;
            swap(s[i], s[j]); i++; j--;
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
