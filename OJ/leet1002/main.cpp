#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, 0);
        int i = 0; string start = A[0];
        for (const auto& si: start) {
            cnt[si-'a'] += 1;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> A = { "bella","label","roller" } ;
    auto ans = sol.commonChars(A);
    for (const auto& ai: ans) cout << ai << ", ";
    return 0;
}
