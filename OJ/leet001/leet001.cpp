#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

/*
    Two Sum
    [哈希] [二分搜索]
*/


class Solution1 {
public:
    vector<int> twoSum(vector<int>& A, int target) { // O(N): 8ms
        unordered_map<int, int> M; std::vector<int> ans(2);
        for (int i=0; i<A.size(); ++i) M.insert({A[i], i});
        for (int i=0; i<A.size(); ++i){
            if (M.find(target-A[i]) != M.end()) {
                ans[0] = i; int j = M[target-A[i]]; bool found = false;
                if (j != i) { ans[1] = j,  found = true; }
                else {
                    for (int j=0; j<A.size(); ++j)
                        if (A[j] == target-A[i] and i != j) { ans[1] = j; found = true; break; }
                }
                if (found) { if (j < i) swap(ans[0], ans[1]); break;}
            }
        }
        // for (auto p: M) printf("%d => %d\n", p.first, p.second);
        // for (auto x: ans) printf("%d ", x);
        return ans;
    }
};

class Solution2 {
public:
    typedef pair<int, int> pii;

    int search(vector<pii>& v, int lo, int hi, int target) const{// 二分
        int mid;
        while (lo < hi) {
            mid = lo + ((hi - lo) >> 1);
            if (v[mid].first == target) return v[mid].second;
            if (v[mid].first < target) lo = mid+1;
            else hi = mid;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& A, int target) { // O(N log N): 4ms
        std::vector<int> ans(2);
        size_t sz = A.size(); std::vector<pii> v;
        for (int i=0; i<sz; ++i) v.push_back(make_pair(A[i], i));
        sort(v.begin(), v.end());
        for (int i=0; i<sz; ++i) {
            int find = search(v, i+1, sz, target-v[i].first);
            if (find != -1) {
                ans[0] = v[i].second, ans[1] = find;
                if (ans[0] > ans[1]) swap(ans[0], ans[1]);
                break;
            }
        }
        // for (auto p: M) printf("%d => %d\n", p.first, p.second);
        // for (auto x: ans) printf("%d ", x);
        return ans;
    }
};

class Solution3 {
public:
    typedef pair<int, int> pii;

    int find(vector<pii>& v, int t, int lft, int rht) {
        int mid;
        while (lft < rht) {
            mid = (lft + rht) / 2;
            if (v[mid].first > t) rht = mid;
            else if (v[mid].first < t) lft = mid+1;
            else return mid;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // for (auto x:nums) printf("%d ", x); printf("\n");
        int sz = nums.size();
        vector<pii> v; vector<int> ans(2);
        for (int i=0; i<sz; ++i) v.push_back(pii(nums[i], i));
        // when sorting pairs, first element is compared by default
        sort(v.begin(), v.end()); 
                                  
        for (int i=sz-1; i >= 0; --i) {
            int j = find(v, target-v[i].first, 0, i);            
            if (j != -1) {
                // printf("v[%d] = (%d, [%d]), v[%d] = (%d, [%d]) \n", i, v[i].first, v[i].second, j, v[j].first, v[j].second);
                ans[0] = v[i].second, ans[1] = v[j].second;
                if (ans[0] > ans[1]) swap(ans[0], ans[1]);
                break;
            }  
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); ++i) { 
            if (auto p = M.find(target - nums[i]); p != M.end()) {
                return {p->second, i};
            }
            M[nums[i]] = i;
        }
        return {};
    }
};

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& vi: v) os << vi << ", "; os << endl;
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row: v) os << row;
    return os;
}

int main(int argc, char const *argv[])
{

    Solution sol;
    cout << sol.twoSum( {2, 7, 9, 11}, 9 );
    
    return 0;
}
