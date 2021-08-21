/*
leet443


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


class Solution {
public:
    int compress(vector<char>& v) {
        auto len_of_int = [](int x) {
            int cnt = 0;
            while (x) cnt++, x /= 10;
            return cnt;
        };

        char prev = v[0]; int cnt = 1, ptr = 0;
        int N = v.size();
        for (int i = 1; i < N; i++)
        {
            auto ch = v[i];
            if (ch == prev) cnt++;
            else {
                int len = len_of_int(cnt);
                v[ptr] = prev;
                if (cnt > 1) {
                    for (int i = len; i >= 1; i--)
                    {
                        v[ptr + i] = cnt % 10 + '0';
                        cnt /= 10;
                    }
                    len++;
                }
                prev = ch, cnt = 1, ptr += len;
            }
        }
        
        
        int len = len_of_int(cnt);
        v[ptr] = prev;
        if (cnt > 1) {
            for (int i = len; i >= 1; i--)
            {
                v[ptr + i] = cnt % 10 + '0';
                cnt /= 10;
            }
            len++;
        }
        ptr += len;
        return ptr;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;   
    {
        vector<char> v = {'a','a','b','b','c','c','c'};
        cout << sol.compress(v) << endl;
        cout << v << endl;
    }
    {
        vector<char> v = {'a'};
        cout << sol.compress(v) << endl;
        cout << v << endl;
    }
    {
        vector<char> v = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
        cout << sol.compress(v) << endl;
        cout << v << endl;
    }
    return 0;
}
