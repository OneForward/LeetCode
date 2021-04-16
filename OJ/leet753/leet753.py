# leet753

from typing import List


class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        # 欧拉回路题
        # 官方递归解法，非常牛逼
        seen = set()
        ans = []
        def dfs(node: str):
            for x in map(str, range(k)):
                next_node = node + x 
                if next_node not in seen:
                    seen.add(next_node)
                    dfs(next_node[1:])
                    ans.append(x)
        dfs("0" * (n-1))
        return "".join(ans) + "0" * (n-1)


print(Solution().crackSafe(3, 4))


