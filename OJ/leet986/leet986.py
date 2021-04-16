# leet986

from typing import List


class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        # 这个解法不是非常优雅
        ans = []
        i2, n2 = 0, len(secondList)
        for v1 in firstList:
            while i2 < n2:
                v2 = secondList[i2]
                if v2[1] < v1[0]: i2 += 1
                elif v2[0] > v1[1]: break 
                else:
                    ans.append([max(v1[0], v2[0]), min(v1[1], v2[1])])
                    i2 += 1
            if i2: i2 -= 1
        return ans  
            
            


print(Solution().intervalIntersection(firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]] ))
print(Solution().intervalIntersection(firstList = [[1,3],[5,9]], secondList = []))
print(Solution().intervalIntersection(firstList = [], secondList = [[4,8],[10,12]]))
print(Solution().intervalIntersection(firstList = [[1,7]], secondList = [[3,10]]))
print(Solution().intervalIntersection([[4,6],[7,8],[10,17]],[[5,10]]))


