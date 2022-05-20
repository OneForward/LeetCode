/*
leet436


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;



class Solution {
public:
    vector<int> findRightInterval(const vector<vector<int>>& intervals) {
        int index[20005]{}, N = intervals.size();
        iota(index, index + N, 0);

        auto cmp = [&](int i, int j) {
            return intervals[i][0] < intervals[j][0];
        };
        sort(index, index + N, cmp);

        auto bisearch = [&](int x) {
            int lft = 0, rht = N;
            while (lft < rht) {
                auto mid = (lft + rht) / 2;
                if (intervals[index[mid]][0] >= x) rht = mid;
                else lft = mid + 1;
            }
            return lft == N ? -1 : index[lft];
        };
        
        vector<int> ans; ans.reserve(N);
        for (auto&& q: intervals) {
            ans.push_back( bisearch(q[1]) );
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.findRightInterval({{1,2}}) << endl;
    cout << sol.findRightInterval({{3,4},{2,3},{1,2}}) << endl;
    cout << sol.findRightInterval({{1,4},{2,3},{3,4}}) << endl;
    cout << sol.findRightInterval({{1,2},{2,3},{0,1},{3,4}}) << endl;
    return 0;
}
