/*
lcci08.08


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
        // 0ms, 100%, 7MB, 68%
        unordered_set<string> M; M.insert(s);
        for (size_t rht = 1; rht < s.size(); rht++)
        {
            unordered_set<string> newM;
            for (const auto& si: M) {
                auto s = si;
                for (size_t i = 0; i < rht; i++)
                {
                    swap(s[rht], s[i]);
                    newM.insert(s);
                    swap(s[rht], s[i]);
                }
            }
            M.merge(newM);
        }
        return vector<string>(M.begin(), M.end());
    }

};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.permutation("aaabb") << endl;
    cout << sol.permutation("abb") << endl;
    cout << sol.permutation("ab") << endl;
    return 0;
}
