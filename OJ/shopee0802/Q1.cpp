/*
shopee0802


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


struct Map {
    string key;
    Map* val;
};

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param inxml string字符串 xml字符串
     * @param path string字符串 取值路径
     * @return string字符串
     */

    // void f(unordered_map<string, >)
    string GetXMLValue(string inxml, string path) {
        
    }
};



int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.GetXMLValue("<people><name>shopee</name></people>","people.age") << endl;
    cout << sol.GetXMLValue("<people><name>shopee</name></people>","people.name") << endl;
    return 0;
}
