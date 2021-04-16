# leet332

from typing import List

from collections import deque 

# 这种「一笔画」问题与欧拉图或者半欧拉图有着紧密的联系，下面给出定义：
# 通过图中所有边恰好一次且行遍所有顶点的通路称为欧拉通路。
# 通过图中所有边恰好一次且行遍所有顶点的回路称为欧拉回路。
# 具有欧拉回路的无向图称为欧拉图。
# 具有欧拉通路但不具有欧拉回路的无向图称为半欧拉图。
# 
# 因为本题保证至少存在一种合理的路径，也就告诉了我们，这张图是一个欧拉图或者半欧拉图。我们只需要输出这条欧拉通路的路径即可。
# 如果没有保证至少存在一种合理的路径，我们需要判别这张图是否是欧拉图或者半欧拉图，具体地：
# 对于无向图 G，G 是欧拉图当且仅当 G 是连通的且没有奇度顶点。
# 对于无向图 G，G 是半欧拉图当且仅当 G 是连通的且 G 中恰有 2 个奇度顶点。
# 对于有向图 G，G 是欧拉图当且仅当 G 的所有顶点属于同一个强连通分量且每个顶点的入度和出度相同。
# 对于有向图 G，G 是半欧拉图当且仅当 G 的所有顶点属于同一个强连通分量且
# 恰有一个顶点的出度与入度差为 1；
# 恰有一个顶点的入度与出度差为 1；
# 所有其他顶点的入度和出度相同。


class Solution1:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        M = {v[0]:[] for v in tickets} 
        for v in tickets:
            M[v[0]].append(v[1])
        for k, v in M.items():
            M[k] = deque(sorted(v, reverse=True))
        
        start = "JFK"
        ans = [start]

        def recursive(start: str):
            if len(ans) == len(tickets) + 1: return True
            if start not in M: return False
            n_next = len(M[start])
            for _ in range(n_next):
                to = M[start].pop()
                ans.append(to)
                if recursive(to):
                    return True 
                ans.pop()
                M[start].appendleft(to)
            return False
        
        recursive(start)
        return ans

from collections import defaultdict
import heapq 


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:

        def dfs(curr: str):
            while M[curr]:
                tmp = heapq.heappop(M[curr])
                dfs(tmp)
            stack.append(curr)

        M = defaultdict(list)
        
        for start, to in tickets:
            M[start].append(to)
        for k, v in M.items():
            heapq.heapify(v)

        stack = []

        dfs("JFK")

        return stack[::-1]

print(Solution().findItinerary([["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]))
print(Solution().findItinerary([["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]))
print(Solution().findItinerary([["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]))


