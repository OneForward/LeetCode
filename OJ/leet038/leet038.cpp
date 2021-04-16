/*
leet038


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector v = {'1'}; 
        while (--n) {
            // for (auto vi: v) cout << vi << ", "; cout << endl;
            vector<char> v2;
            int i = 1, cnt = 1;
            while (i < v.size()) {
                if (v[i] == v[i-1]) cnt++;
                else {
                    v2.push_back(cnt + '0'); v2.push_back(v[i-1]); cnt = 1;
                }
                ++i;
            }
            v2.push_back(cnt + '0'); v2.push_back(v[i-1]);
            v = v2;
        }
        return string(v.begin(), v.end()) ;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.countAndSay(4);

    return 0;
}
