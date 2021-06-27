/*
leet526


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;

class Solution {
public:

    int countArrangement(int n) {
        // 使用全排列的模板写法即可，增加一个剪枝条件
        vector<int> path; int ans = 0;
        vector<bool> used(n+1);
        function<void()> f = [&]() {
            if (path.size() == n) { ans++; return; }
            for (size_t i = 1; i <= n; i++)
            {
                if (used[i]) continue;
                auto j = path.size() + 1;
                if (i % j and j % i) continue;
                path.push_back(i); used[i] = true;
                f();
                path.pop_back(); used[i] = false;
            }
        };

        f();

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.countArrangement(2) << endl;
    cout << sol.countArrangement(3) << endl;
    return 0;
}
