/*
leet621


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


class Solution {
public:
    int leastInterval(const vector<char>& tasks, int n) {
        // 贪心, O(N)
        int Counter [26]{}, maxVal = 0, same = 0;
        int len = tasks.size();
        for (auto&& ch: tasks) {
            Counter[ch - 'A']++;
            maxVal = max(maxVal, Counter[ch - 'A']);
        }
        
        for (auto&& cnt: Counter) {
            if (cnt == maxVal) same++;
        }
        return max((maxVal - 1) * (n + 1) + same, len);
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.leastInterval({'A','A','A','B','B','B'}, 2) << endl;
    cout << sol.leastInterval({'A','A','A','B','B','B'}, 0) << endl;
    cout << sol.leastInterval({'A','A','A','A','A','A','B','C','D','E','F','G'}, 2) << endl;
    return 0;
}
