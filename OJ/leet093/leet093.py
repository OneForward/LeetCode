def f(s, i, cnt): 
    if i == len(s) and cnt == 4: return [[]]
    if i != len(s) and cnt == 4: return []

    v1, v2, v3 = [], [], []
    if i <= len(s)-1:
        v1 = f(s, i+1, cnt+1)
    if i <= len(s)-2 and 10 <= int(s[i:i+2]):
        v2 = f(s, i+2, cnt+1)
    if i <= len(s)-3 and 100 <= int(s[i:i+3]) <= 255:
        v3 = f(s, i+3, cnt+1)
    
    for vi in v1: vi.append(s[i:i+1])
    for vi in v2: vi.append(s[i:i+2])
    for vi in v3: vi.append(s[i:i+3])
    return v1 + v2 + v3
    

class Solution:
    # 44ms
    def restoreIpAddresses(self, s: str):
        L = f(s, 0, 0) 
        return [ ".".join(reversed(vi)) for vi in L ]


print(Solution().restoreIpAddresses("25525511135"))
print(Solution().restoreIpAddresses("0000"))
print(Solution().restoreIpAddresses("010010"))
# print(f("25525511135", 0, 0))