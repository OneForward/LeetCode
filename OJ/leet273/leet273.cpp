/*
leet273


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;
string Ones[] = {
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
};
string Teens[] = {
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
};
string Tens[] = {
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety",
};
string Thousands[] = {
    "",
    "Thousand",
    "Million",
    "Billion",
};
class Solution {
public:
    string f(int x) {
        int a = x / 100, b = x / 10 % 10, c = x % 10;
        vector<string> v;
        if (a) v.push_back( Ones[a]), v.push_back( "Hundred");
        if (b == 1) { v.push_back( Teens[c]); goto end; }
        if (b) v.push_back( Tens[b]);
        if (c) v.push_back( Ones[c]);
        if (v.size() == 0) return {};
        end:
        string s = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            s += " " + v[i];
        }
        return s;
    }
    string numberToWords(int x) {
        if (x == 0) return "Zero";
        vector<string> v;
        while (x) {
            v.push_back(f(x % 1000)); x /= 1000;
        }
        string s;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i].size()) s += v[i] + " " + Thousands[i] + " ";
        }
        while (s.back() == ' ') s.pop_back();
        return s;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.numberToWords(123) << endl;
    cout << sol.numberToWords(12345) << endl;
    cout << sol.numberToWords(1234567) << endl;
    cout << sol.numberToWords(1234567891) << endl;
    return 0;
}
