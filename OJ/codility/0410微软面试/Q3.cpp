/*
codility


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
#include "../utils/LeetCpp.utils.hpp"

using namespace std;



int solution(vector<int> A, vector<int> B) {
    int N = A.size();
    
    vector<int> indegree(N+1);
    vector<int> outdegree(N+1);
    for (auto&& px: B) indegree[px]++;
    for (auto&& x: A) outdegree[x]++;
    int ans = -1;
    for (int x = 0; x <= N; x++)
    {
        if (outdegree[x] == 0 and indegree[x]) {
            if (ans >= 0) return -1;
            ans = x;
        }
    }
    
    return ans;
}


int main(int argc, char const *argv[])
{
    cout << solution  ( {1,0}, {0,1} ) << endl;
    cout << solution  ( {1,2,3}, {0,0,0} ) << endl;
    cout << solution  ( {0,1,2,4,5}, {2,3,3,3,2} ) << endl;
    cout << solution  ( {2,3,3,4}, {1,1,0,0} ) << endl;
    
    return 0;
}
