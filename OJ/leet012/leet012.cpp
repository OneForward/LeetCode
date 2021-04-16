/*
leet012


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
    

    Solution solution;
    vector<vector<int>> ans = solution.threeSum(v);
    for (auto x: ans) {
        printf("[ ");for (auto e: x) printf("%d, ", e); printf("], \n");
    }

    return 0;
}
