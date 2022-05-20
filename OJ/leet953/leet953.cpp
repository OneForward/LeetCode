/*
leet953


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    bool isAlienSorted(const vector<string>& words, const string& order) {
        int A[26]{}, rank = 0;
        for (auto&& ch: order) A[ch - 'a'] = rank++;

        auto cmp = [&](const string& lft, const string& rht) {
            size_t i = 0; auto N = lft.size(), M = rht.size();
            while (i < N and i < M and lft[i] == rht[i]) ++i;
            int x = (i == N) ? -1 : A[lft[i] - 'a'];
            int y = (i == M) ? -1 : A[rht[i] - 'a'];
            return x <= y;
        };

        int i = 1, N = words.size();
        while (i < N and cmp(words[i-1] , words[i])) ++i;
        return i >= N;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   cout << boolalpha;
    cout << sol.isAlienSorted( {"hello","leetcode"},  "hlabcdefgijkmnopqrstuvwxyz") << endl;
    cout << sol.isAlienSorted( {"word","world","row"},  "worldabcefghijkmnpqstuvxyz") << endl;
    cout << sol.isAlienSorted( {"apple","app"},  "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}
