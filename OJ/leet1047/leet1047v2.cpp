#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        vector<int> f(n);  f[n - 1] = n - 2;
        for (int i = n - 2; i >= 0; i--)
        {
            auto next = f[i+1] + 1;
            if (next < n and f[next] == next - 1 and s[i] == s[next]) {
                if (next < n-1 and f[next+1] != next) f[i] = f[next+1];
                else f[i] = next;
            }
            else f[i] = i - 1;
        }
        string ans;
        int i = 0;
        while (i < n)
        {
            if (f[i] == i-1) 
                ans.push_back(s[i]), i++;
            else i = f[i] + 1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.removeDuplicates("ibfjcaffccadidiaidchakchchcahabhibdcejkdkfbaeeaecdjhajbkfebebfea") << endl;
    cout << sol.removeDuplicates("aaaaaa") << endl;
    cout << sol.removeDuplicates("abbaca") << endl;
    return 0;
}
