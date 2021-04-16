# leet318

from typing import List

from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # Time O(N^2+L)
        # Space O(N)
        hashmap = defaultdict(int)
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))
        
        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod




print(Solution().maxProduct(["abcw","baz","foo","bar","xtfn","abcdef"]))
print(Solution().maxProduct(["a","aa","aaa","aaaa"]))


