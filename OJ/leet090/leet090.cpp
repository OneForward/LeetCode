/*
leet090

递归，回溯
*/


#include <iostream>
#include <vector>
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
    vector<vector<int>> subsetsWithDup(vector<int>& v, int start) {
        // 8ms
        int next_start = start + 1;
        while (next_start < v.size() && v[next_start] == v[next_start-1]) next_start++;
        if (next_start > v.size()) return {{}};

        auto no = subsetsWithDup(v, next_start);
        auto yes = no, ans = no;
        while (start < next_start) {
            for (auto& vi: yes) vi.push_back(v[start]);
            ans.insert(ans.end(), yes.begin(), yes.end());
            start++;
        }
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        return subsetsWithDup(v, 0);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v  = {1, 2, 2,  };
    Solution sol;   
    cout << sol.subsetsWithDup(v) << endl;
    return 0;
}
