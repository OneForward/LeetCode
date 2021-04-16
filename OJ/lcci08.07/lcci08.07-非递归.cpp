/*
lcci08.07


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> M; M.push_back(s);
        for (size_t rht = 1; rht < s.size(); rht++)
        {
            auto len = M.size();
            while (len--) {
                auto s = M[len];;
                for (size_t i = 0; i < rht; i++)
                {
                    swap(s[rht], s[i]);
                    M.push_back(s);
                    swap(s[rht], s[i]);
                }
            }
        }
        return M;
    }

};




int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("abc") << endl;
    cout << sol.permutation("ab") << endl;
    return 0;
}
