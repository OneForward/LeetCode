/*
leet338


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

class Solution {
public:
    vector<int> countBits1(int num) {
        vector<int> v(num+1);
        for (int i = 1; i <= num; ++i) {
            v[i] = v[ i - (i&(-i)) ] + 1;
        }
        return v;
    }
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        for (int i = 1; i <= num; ++i) {
            v[i] = v[ i & (i-1) ] + 1;
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countBits(10);
    return 0;
}
