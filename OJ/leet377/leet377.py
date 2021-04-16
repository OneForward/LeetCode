# leet377

from typing import List


class Solution:
    def combinationSum4(self, Ws: List[int], target: int) -> int:
        # f(v) = sum f(v - wi) for wi in Ws 
        # 由于有顺序, f(v) 表示这 N 个物品能够填充的方法数目
        # 对于容量 v 的包裹，第一个位置放入 wi, 则剩余开放有 f(v-wi)
        n = len(Ws)
        f = [0] * (target+1)
        f[0] = 1
        for v in range(1, target+1):
            for wi in Ws:
                if v >= wi:
                    f[v] += f[v-wi]
        return f[target]



print(Solution().combinationSum4([1,2,3], 4))


