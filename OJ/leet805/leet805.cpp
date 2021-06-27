/*
leet805


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    struct Pair
    {
        int sum, len;
    };
    
    vector<Pair>  f(vector<int> A) {
        int n = A.size();
        vector<Pair> f(1<<n);
        for (size_t x = 0; x < n; x++)
            f[1<<x] = { A[x] , 1 };
        
        for (size_t x = 1; x < (1<<n); x++)
        {
            auto [sum, len] = f[x & (x-1)];
            f[x] = { f[x & -x].sum + sum, len + 1 };
        }
        return vector<Pair>(f.begin()+1, f.end());
    }
    bool splitArraySameAverage( vector<int> A) {
        int n = A.size(), total = reduce(A.begin(), A.end(), 0);
        for (auto &&x : A) x = x * n - total;
        
        if (n <= 1) return false;

        vector<int> Alft(A.begin(), A.begin() + n/2);
        vector<int> Arht(A.begin()+n/2, A.begin() + n);
        auto flft = f(Alft);
        auto frht = f(Arht);
        
        for (auto &&[x, _] : flft) if (x == 0) return true;
        for (auto &&[x, _] : frht) if (x == 0) return true;

        unordered_set<int, int> Mlft, Mrht;
        for (auto &&[x, len] : flft) Mlft.insert(x);
        for (auto &&[x, len] : frht)
        {
            if (Mrht.find(x) == Mrht.end()) Mrht[x] = len;
            else Mrht[x] = min(Mrht[x], len);
        }
        
        for (auto &&[x, len] : Mlft)
        {
            if (Mrht.find(-x) != Mrht.end()) {
                if (Mrht[-x] + len != n) return true;
            }
        }
        
        return false;
    }
};


int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.splitArraySameAverage({10,29,13,53,33,48,76,70,5,5}) << endl;
    cout << sol.splitArraySameAverage({3,1}) << endl;
    cout << sol.splitArraySameAverage({18,10,5,3}) << endl;
    cout << sol.splitArraySameAverage({1,2,3,4,5,6,7,8}) << endl;
    cout << sol.splitArraySameAverage({0}) << endl;
    
    return 0;
}
