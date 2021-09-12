/*
tencent0910


*/

// #include "../utils/LeetCpp.utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

using VI=vector<int>;
using u32 = unsigned int;

u32 random_large() {
	u32 x = rand(), y = rand();
    return (x << 16 )+ y;
}

VI random_choice(u32 N, u32 k) {
    VI A(N);
    for (u32 i = 0; i < N; i++) {
        A[i] = i;
    }
    
    VI B;
    for (auto&& x: A) {
        u32 len = B.size();
        u32 j = random_large() % (len + 1);
        if (j == len) B.push_back(x);
        else {
            B.push_back(B[j]);
            B[j] = x;
        }
        if ((u32)B.size() == k) break;
    }
    return B;
}

int main()
{
    // int N = 300000, K = 100000;
    int N = 30, K = 10;
    auto ans = random_choice(N, K);
    for (auto&& i: ans) {
        cout << i << ", ";
    }
    return 0;
}
