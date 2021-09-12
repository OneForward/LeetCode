/*
tencent0910


*/

// #include "../utils/LeetCpp.utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

// #define ALL(A) A.begin(),A.end()
// using VI=vector<int>;
// using VVI=vector<VI>;


int LIS(const vector<int>& A) {
    // O(N log N)
    vector<int> tails; 
    for (const auto& x: A) {
        auto pos = lower_bound(tails.begin(), tails.end(), x);
        if (pos == tails.end()) tails.push_back(x);
        else if (x < *pos) *pos = x;
    }
    return tails.size();
}

int main()
{
    cout << LIS( { 7, 2, 3, 1, 5, 8, 9, 6  } ) << endl;
    return 0;
}
