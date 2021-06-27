/*
leet1006


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        if (N <= 2) return N;
        if (N == 3) return 6;
        if (N == 4) return 7;
        switch (N % 4)
        {
        case 0: return N + 1;
        case 1: return N + 2;
        case 2: return N + 2;
        case 3: return N - 1;
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    
    return 0;
}
