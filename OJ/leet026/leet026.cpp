/*
leet026


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int top = 0;
        for (int j=1; j<v.size(); ++j) {
            if (v[j] != v[top]) v[++top] = v[j];
        }
        return v.size() ? top+1 : 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1};
    
    Solution sol;
    printf("ans = %d\n", sol.removeDuplicates(v));

    for (auto vi: v) printf("%d, ", vi);
    

    return 0;
}
