/*
leet520


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }
        
        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < (int)word.size(); ++i) {
            if (islower(word[i]) ^ islower(word[1])) {
                return false;
            }
        }
        return true;
    }
}; 

int main(int argc, char const *argv[])
{
    cout << boolalpha;

    Solution sol;   
    cout << sol.detectCapitalUse("abc") << endl;
    cout << sol.detectCapitalUse("US") << endl;
    cout << sol.detectCapitalUse("FlaG") << endl;
    cout << sol.detectCapitalUse("Flag") << endl;
    return 0;
}
