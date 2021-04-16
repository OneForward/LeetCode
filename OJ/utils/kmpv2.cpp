#include <iostream>
#include <string>
#include "LeetCpp.utils.hpp"
using namespace std;

int issubstr(string sub, string s) {
    auto m = sub.size(), n = s.size();
    vector<int> next(m); next[0] = -1;

    int pi = -1; 
    for (int i=1; i<m; ++i) {
        while (pi >= 0 and sub[pi+1] != sub[i]) pi = next[pi];
        if (sub[pi+1] == sub[i]) ++pi;
        next[i] = pi;
    }
    cout << next << endl;
    
    int i = 0; pi = -1;
    while (i < n and pi < m-1){
        while (pi >= 0 and sub[pi+1] != s[i]) pi = next[pi];
        if (sub[pi+1] == s[i]) ++pi;
        ++i;
    }
    if (pi == m-1) printf("pos = %d\n", i-m);
    if (i == n) printf("Not matched\n");
    return pi == m-1 ? i - m : -1;
}


int main(int argc, char **argv)
{
	issubstr("abcdababcd", "abcdababcdxxx");
	return 0;
}
