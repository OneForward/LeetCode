# lccup0405

from typing import List


class Solution:
    def orchestraLayout(self, num: int, Xpos: int, Ypos: int) -> int:
        N, x, y = num, Xpos, Ypos
        L = min(abs(x), abs(y), abs(N-1-x), abs(N-1-y))
        ans = 4 * (N - L) * L 
        if y >= x: ans += max(x - L, 0) + y - L 
        else: ans += 2 * (N - 2 * L - 1) + max(N - L - 1 - x, 0) + N - L - 1 - y 
        return ans % 9 + 1

for N in (3, 4):
    print()
    for x in range(N):
        for y in range(N):
            print(Solution().orchestraLayout(N, x, y), end=', ')
        print()

print(Solution().orchestraLayout(num = 3, Xpos = 0, Ypos = 2))
print(Solution().orchestraLayout(num = 4, Xpos = 1, Ypos = 2))


