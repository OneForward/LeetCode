/*
leet049


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VS=vector<string>;
using VVS=vector<VS>;
using LL = long long int;

const LL MOD = 1e9 + 7;
LL hashfunc(const string& s) {
    LL x = 0;  char f[26]{};
    for (auto&& ch: s) {
        f[ch - 'a']++;
    }
    for (auto&& cnt: f) {
        x = (x * 101 + cnt) %  MOD;
    }
    return x;
};
class Solution {
public:
    VVS groupAnagrams(const VS& strs) {
        VVS ans;
        unordered_map<LL, size_t> M;
        for (auto&& word: strs) {   
            auto x = hashfunc(word);
            if (M.find(x) != M.end()) { ans[M[x]].push_back(word); }
            else M[x] = ans.size(), ans.push_back({word});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}) << endl;
    cout << sol.groupAnagrams({""}) << endl;
    cout << sol.groupAnagrams({"a"}) << endl;
    return 0;
}
