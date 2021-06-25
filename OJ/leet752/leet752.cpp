/*
leet752


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int openLock(const vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        bool visited[10000]{};
        for (auto&& s: deadends) {
            visited[stoi(s)] = true;
        }
        if (visited[0]) return -1;

        int bits[4]{}, ans = 0, targetInt = stoi(target);
        queue<int> Q; Q.push(0); visited[0] = true;
        
        auto recover = [&]() {
            auto&& [a, b, c, d] = bits;
            return a + b * 10 + c * 100 + d * 1000;
        };

        auto reset = [&](int p) {
            for (int i = 0; i < 4; i++) {
                bits[i] = p % 10, p /= 10;
            }
        };

        while (Q.size()) {
            int len = Q.size(); ans++;
            while (len--) {
                int p = Q.front(), newp; Q.pop(); 
                
                for (auto&& bit: bits) {
                    reset(p); bit = (bit + 1) % 10; newp = recover(); 
                    if (not visited[newp]) visited[newp] = true, Q.push(newp);
                    if (newp == targetInt) goto last;

                    reset(p); bit = (bit + 9) % 10; newp = recover(); 
                    if (not visited[newp]) visited[newp] = true, Q.push(newp);
                    if (newp == targetInt) goto last;
                }
            }
        }
        return - 1;

        last:  return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.openLock({"0201","0101","0102","1212","2002"}, "0202") << endl;
    cout << sol.openLock({"8888",}, "0009") << endl;
    cout << sol.openLock({"8887","8889","8878","8898","8788","8988","7888","9888",}, "8888") << endl;
    cout << sol.openLock({"0000",}, "8888") << endl;
    return 0;
}
