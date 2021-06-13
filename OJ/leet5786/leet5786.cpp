/*
weekly-245


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;

class Solution {
public:
    int maximumRemovals(string s, string p, const vector<int>& removable) {
        

        auto isok = [&](int k) {
            auto S = s;
            for (int i = 0; i < k; i++)
            {
                S[removable[i]] = 'A';
            }
            size_t pos = 0;
            for (auto&& pi: p) {
                pos = S.find(pi, pos);
                if (pos == string::npos) return false;
                pos++;
            }
            return true;
        };


        int lft = 1, rht = removable.size() + 1;

        while (lft < rht) {
            auto mid = (lft + rht) / 2;
            if (not isok(mid)) rht = mid;
            else lft = mid + 1;
        }
        return lft - 1;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.maximumRemovals("abcacb", "ab", {3,1,0}) << endl;
    cout << sol.maximumRemovals("abcbddddd",  "abcd", {3,2,1,4,5,6}) << endl;
    cout << sol.maximumRemovals("abcab",  "abc", {0,1,2,3,4}) << endl;
    return 0;
}
