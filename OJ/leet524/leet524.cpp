/*
leet524


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    string findLongestWord(string s, const vector<string>& dictionary) {
        auto cmp = [](const string& lft, const string& rht) {
            auto M = lft.size(), N = rht.size();
            if (M < N) return true;
            if (M > N) return false;
            return lft > rht;
        };

        string ans;
        auto issubseq = [&](const string& s, const string& word) {
            int i = 0, j = 0;
            int N = s.size(), M = word.size();
            while (i < N and j < M)  {
                if (s[i] != word[j]) i++;
                else i++, j++;
            }
            return j == M;
        };

        for (auto&& word: dictionary) {
            if (issubseq(s, word) and cmp(ans, word))  ans = word;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findLongestWord( "abpcplea", {"ale","apple","monkey","plea"}) << endl;
    cout << sol.findLongestWord( "abpcplea", {"a","b","c"}) << endl;
    cout << sol.findLongestWord( "aewfafwafjlwajflwajflwafj", {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"}) << endl;
    return 0;
}
