
Ks = "IVXLCDM"
Vs = [1, 5, 10, 50, 100, 500, 1000]
D = dict(zip(Ks, Vs))
print(D)
class Solution:
    def romanToInt(self, s: str) -> int:
        x = 0
        for i in range(len(s)-1):
            if D[s[i]] < D[s[i+1]]:
                x -= D[s[i]]
            else:
                x += D[s[i]]
        x += D[s[-1]]
        return x 

Solution().romanToInt("MCMXCIV")
Solution().romanToInt("LVIII")
Solution().romanToInt("IX")
Solution().romanToInt("IV")
Solution().romanToInt("III")
