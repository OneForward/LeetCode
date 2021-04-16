/*
leet763


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
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(const string& S) {
        // O(N), 4ms
        int Mrht[26];
        for (int i = 0; i < S.size(); ++i) 
            Mrht[S[i] - 'a'] = i;
        
        vector<int> ans;
        int lft = 0, rht = 0;
        for (int i = 0; i < S.size(); ++i) {
            rht = max(rht, Mrht[S[i]-'a']);
            if (i == rht) ans.push_back(rht-lft+1), lft = rht = i+1;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.partitionLabels("ababcbacadefegdehijhklij") << endl;
    return 0;
}
