/*
leet313


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
using namespace std;

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

struct Tuple
{
    int val;
    int prime;
    int val_idx;
};


class Solution {
public:
    int nthSuperUglyNumber1(int n, const vector<int>& primes) {
        // Time O(n log k) , 344ms
        auto cmp = [](const Tuple& lft, const Tuple& rht) {
            return lft.val > rht.val;
        };
        
        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> Q(cmp);

        vector<int> ans(n); ans[0] = 1;
        for (auto p: primes) Q.push({p, p, 0});
        for (int i = 1; i < n; ++i) {
            do {
                auto [x, p, idx] = Q.top(); Q.pop();
                ans[i] = x; idx++;
                Q.push( { ans[idx] * p,  p , idx} );
                if (x > ans[i-1]) break;
            } while (true);
        }
        // cout << ans;
        return ans.back();
    }

    int nthSuperUglyNumber(int n, const vector<int>& primes) {
        // Time O(n k) , 52ms
        int k = primes.size();
        vector<int> ans(n); ans[0] = 1;
        vector<int> factors( k );
        for (int i = 1; i < n; ++i) { 
            int min_j, min_val = INT_MAX;
            for (int j = 0; j < k ; ++j) {
                auto prod = ans[factors[j]] * primes[j] ;
                if ( prod == ans[i-1] ) {
                    factors[j]++, prod = ans[factors[j]] * primes[j];
                }
                if ( prod < min_val )  {
                    min_val = prod; min_j = j;
                }
            }
            factors[min_j]++; ans[i] = min_val;
        }
        // cout << ans;
        return ans.back();
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.nthSuperUglyNumber(12, {2,7,13,19}) << endl;
    return 0;
}
