/*
leet371


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
#include <bitset>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // NOTES: left shift of negtive value in C++ is undefined-behavior
        // so use unsigned int instead
        cout << "a = " << bitset<32>(a) << ", b = " << bitset<32>(b)  << endl;

        int sum = a ^ b;
        unsigned int check = a & b;
        while (check) {
            cout << "check = " << bitset<32>(check) << ", sum = " << bitset<32>(sum)  << endl;
            check <<= 1; 
            auto tmp_sum = sum;
            sum ^= check; check &= tmp_sum;
        }
        return sum;
    }
};


int main(int argc, char const *argv[])
{
    // cout << bitset<4>(-1) << endl;
    Solution sol;   
    // cout << sol.getSum(5, 7) << endl;
    cout << sol.getSum(-1, 1) << endl;
    // cout << sol.getSum(-2, 3) << endl;
    // cout << sol.getSum(2, 3) << endl;
    // cout << sol.getSum(1, 3) << endl;
    return 0;
}
