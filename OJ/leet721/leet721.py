# leet721

from typing import List


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        P = [-1]  * len(accounts)
        def find(i):
            if P[i] < 0: return i 
            P[i] = find(P[i]) 
            return P[i]
        def merge(i, j):
            ri, rj = find(i), find(j)
            if ri == rj: return 
            if P[ri] < P[rj]: P[ri] += P[rj]; P[rj] = ri 
            else: P[rj] += P[ri]; P[ri] = rj 

        mail2pos = {}
        for i, mails in enumerate(accounts):
            mails = mails[1:]
            for mail in mails:
                if mail in mail2pos:
                    merge(i, mail2pos[mail]) 
            for mail in mails:
                mail2pos[mail] = i 
        
        from collections import defaultdict 
        pos2mails = defaultdict(list)
        for mail, i in mail2pos.items():
            pos2mails[find(i)].append(mail)
        
        ans = []
        for key, vals in pos2mails.items():
            ans.append([accounts[key][0], *sorted(vals)])

        return ans



print(Solution().accountsMerge( [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]))

print(Solution().accountsMerge([["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]))

