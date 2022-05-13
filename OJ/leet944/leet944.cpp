/*
leet944


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int minDeletionSize(const vector<string>& strs) {
        auto L = strs[0].size();
        int ans = 0;
        for (size_t i = 0; i < L; i++)
        {
            auto prev = 'a';
            for (auto&& s: strs) {
                if (s[i] < prev) {
                    ans++;
                    break;
                }
                prev = s[i];
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.minDeletionSize({"cba","daf","ghi"}) << endl;
    cout << sol.minDeletionSize({"a","b"}) << endl;
    cout << sol.minDeletionSize({"zyx","wvu","tsr"}) << endl;
    return 0;
}
