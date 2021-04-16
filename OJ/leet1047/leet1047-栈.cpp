#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        string f;
        for (auto &&si : s)
        {
            if (f.size() and f.back() == si) f.pop_back();
            else f.push_back(si);
        }
        return f;
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
