#include <cstdio>
#include <cstring>

using namespace std;

void issubstr(const char sub[], const char str[]) {
    int m = strlen(sub);
    int n = strlen(str);
    int* next = new int[m];
    int pi = -1; next[0] = -1;
    for (int i=1; i<m; ++i) {
        while (pi >= 0 and sub[pi+1] != sub[i]) pi = next[pi];
        if (sub[pi+1] == sub[i]) ++pi;
        next[i] = pi;
    }
    for (int i=0; i<m; ++i) printf("next[%d] = %d\n", i, next[i]);
    
    int i = 0; pi = -1;
    while (i < n and pi < m-1){
        while (pi >= 0 and sub[pi+1] != str[i]) pi = next[pi];
        if (sub[pi+1] == str[i]) ++pi;
        ++i;
    }
    if (pi == m-1) printf("pos = %d\n", i-m);
    if (i == n) printf("Not matched\n");
}


int main(int argc, char **argv)
{
    issubstr("abcdababcd", "abcdababcdxxx");
	return 0;
}
