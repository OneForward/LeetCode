/*
leet721


*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;




class Solution {
public:
    vector<int> P;
    unordered_map<string, int> m2p;
    unordered_map<int, vector<string>> p2m;
    
    int find(int i) {
        if (P[i] < 0) return i;
        return P[i] = find(P[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;
        if (P[ri] < P[rj]) P[ri] += P[rj], P[rj] = ri;
        else P[rj] += P[ri], P[ri] = rj;
    }


    vector<vector<string>> accountsMerge(const vector<vector<string>>& accounts) {
        int n = accounts.size();
        P = vector<int>(n, -1);
        for (int i = 0; i < n; ++i) { 
            auto mails = accounts[i];
            for (int j = 1; j < mails.size(); ++j) { 
                if (m2p.count(mails[j]) > 0) merge(m2p[mails[j]], i);
                m2p[mails[j]] = i;
            }
        }

        for (const auto& [mail, i]: m2p) {
            p2m[find(i)].push_back(mail);
        }

        vector<vector<string>> ans;
        for ( auto& [i, mails]: p2m) {
            vector<string> ai = {accounts[i][0]};
            sort(mails.begin(), mails.end());
            ai.insert(ai.end(), mails.begin(), mails.end());
            ans.push_back(ai);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.accountsMerge({{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}}) << endl;
    return 0;
}
