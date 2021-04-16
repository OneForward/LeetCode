/*
leet076


*/


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <utility>
#include <bitset>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 80ms
        unordered_map<char, size_t> SD, TD;
        int lft = 0, rht = 0, ans = INT_MAX, minlft, minrht, cnt = 0, lenTD;
        for (const auto& ti: t) TD[ti]++; lenTD = TD.size();
        while ( lft < s.size() && TD[s[lft]] == 0 ) lft++;
        rht = lft; 
        while ( rht < s.size()) {
            if (TD[s[rht]]) {  
                SD[s[rht]]++; 
                if (SD[s[rht]] == TD[s[rht]]) cnt++;
            }
            if ( cnt == lenTD ) break;
            rht++;
        }
        if (cnt < lenTD) return {};
        if (rht - lft < ans) ans = rht - lft, minlft = lft, minrht = rht;
        if ( ans == 0 ) return s.substr(lft, 1);
        
        
        while (rht < s.size())  {
            char key = s[lft]; SD[key]--;
            lft++; 
            while ( TD[s[lft]] == 0 ) lft++;

            
            while (SD[key] < TD[key] && ++rht < s.size() ){
                if (TD[s[rht]]) SD[s[rht]]++; 
                if (SD[key] >= TD[key]) break;
                
            }
            
            
            if (rht == s.size()) break;
            if (rht - lft < ans) ans = rht - lft, minlft = lft, minrht = rht;
        } ;
        return s.substr(minlft, ans+1);
    }
    string minWindow2(string s, string t) {
        // only support that when s comes from 26 Captal Letters
        int TD[26]{}, SD[26]{};
        int lft = 0, rht = 0, found = ~0, ans = INT_MAX, minlft, minrht;
        for (const auto& ti: t) TD[ti-'A']++, found &= ~(1 << (ti-'A'));
        // cout << "found = " << bitset<32>(found) << endl;
        do  {
            while ( lft < s.size() && TD[s[lft]-'A'] == 0 ) lft++;
            rht = lft;
            while ( rht < s.size() && ~found) {
                if (TD[s[rht]-'A']) {  
                    if (SD[s[rht]-'A'] < TD[s[rht]-'A']) SD[s[rht]-'A']++; 
                    if (SD[s[rht]-'A'] == TD[s[rht]-'A']) found |= 1 << (s[rht]-'A');
                }
                rht++;
            }
            if (rht - lft < ans) ans = rht - lft, minlft = lft, minrht = rht;
            if (ans == 0) return s.substr(lft, 1);
            
            found &= ~(1 << (s[lft]-'A'));
            lft++;
        } while (rht < s.size());
        return s.substr(minlft, ans+1);
    }
};


int main(int argc, char const *argv[])
{

    Solution sol;   

    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("aa", "a") << endl;
    cout << sol.minWindow("ab", "b") << endl;
    cout << sol.minWindow("aa", "aa") << endl;
    return 0;
}
