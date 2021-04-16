/*
leet080


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        // 8ms
        if (v.empty()) return 0;
        int lft = 0, rht = 1, cnt = 1;
        while (rht < v.size()) {
            if (v[rht] == v[lft]) {
                if (cnt < 2) v[++lft] = v[rht], cnt++;
            }
            else {
                v[++lft] = v[rht], cnt = 1;
            }
            rht++;
        }
        return lft+1;

    }
};


int main(int argc, char const *argv[])
{
    vector v = { 1,1,1,2,2,3, };
    // vector v = { 0,0,1,1,1,1,2,3,3 };
    Solution sol;   
    cout << sol.removeDuplicates(v) << endl;
    for (auto vi: v) cout << vi << ", "; cout << endl;
    return 0;
}
