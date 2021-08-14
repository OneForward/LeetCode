# shopee0802
# %%
from typing import List
from pprint import pprint

def init(dims, filled_value = 0):
    if not dims: return filled_value
    return [init(dims[1:], filled_value) for _ in range(dims[0])]



#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param inxml string字符串 xml字符串
# @param path string字符串 取值路径
# @return string字符串
#

from collections import defaultdict

import re 

ans = []
# def parse(s: str):
#     if not s: 
#     if s[0] != '<':
#         j = s.find('<')
#         head = s[:j]

#     else:
#         i = s.find('<')
#         j = s.find('>', 0)
#         head = s[i:j+1]
#     ans.append(head)
#     parse(s[j+1:])
parse("<people><name>shopee</name></people>")
print(ans)
class Solution:
    def GetXMLValue(self, inxml: str, path: str) :
        # write code here
        start = re.findall('<(.*?)>', inxml)
        
        path = path.split('.')
        def f(lft, rht):
            D = {}
            i = lft
            for i in range(lft, rht):
                name = start[lft]
                if start[i] == f'/{name}': 
                    D[name] = f(lft+1, i)
                    lft = i + 1

            return D
        return f(0, len(start))


D = Solution().GetXMLValue("<people><name>shopee</name></people>","people.name")

print(D)
# pprint(Solution().GetXMLValue("<people><name>shopee</name></people>","people.name"))
# pprint(Solution().GetXMLValue("<people><name>shopee</name></people>","people.age"))
# %%

