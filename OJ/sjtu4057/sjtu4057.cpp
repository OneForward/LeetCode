
/* 
最长回文字符串
*/

#include <iostream>
#include <cstring>
using namespace std;

char str[10005];

bool isreverse(int st, int ed) {
    for (int i=0; i < (ed-st+1)/2; ++i) 
        if (str[st+i] != str[ed-i]) return false;
    return true;
}

int main(int argc, char **argv)
{
//    freopen("1.in.txt", "r", stdin);
    
    cin.getline(str, sizeof str);
    int max_reverse = 0, max_i = -1, max_j = -1;
    int len = strlen(str);
    for (int i=0; i<len; ++i) {
        for (int j=i+max_reverse+1; j<len; ++j) {
            if (isreverse(i, j)) {
                if (max_reverse < j - i + 1) {
                    max_reverse = j - i + 1;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }
    cout << max_reverse;
    if (max_reverse) {
        cout << endl;
        for (int i=max_i; i<=max_j; ++i) cout << str[i];
    }
	return 0;
}
