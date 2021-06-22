/*
lcof38


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
class Solution {
public:
    vector<string> permutation(string s) {
        sort(ALL(s));

        vector<string> ans;
        do {
            ans.push_back(s);
        } while (next_permutation(ALL(s)));
        return ans;
    }

};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("abbcc") << endl;
    return 0;
}
