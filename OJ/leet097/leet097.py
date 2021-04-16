class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3): return False
        f = [[False] * (len(s2)+1) for _ in range(len(s1)+1) ]
        f[0][0] = True
        for i in range(1, len(s1)+1):
            if s3[i-1] == s1[i-1]: f[i][0] = True 
            else: break 
        for j in range(1, len(s2)+1):
            if s3[j-1] == s2[j-1]: f[0][j] = True 
            else: break 

        for i in range(1, len(s1)+1):
            for j in range(1, len(s2)+1):
                if (s3[i+j-1] == s1[i-1] and f[i-1][j]) or (s3[i+j-1] == s2[j-1] and f[i][j-1]):
                    f[i][j] = True
                
        return f[len(s1)] [len(s2)]

print(Solution().isInterleave(s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"))
print(Solution().isInterleave(s1 = "a", s2 = "", s3 = "a"))
print(Solution().isInterleave(s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"))