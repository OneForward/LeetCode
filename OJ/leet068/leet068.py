# leet068

from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = [[]]
        L = [0]
        for word in words:
            if L[-1] + len(word) > maxWidth: 
                lines.append([word]); L.append( len(word) + 1)
            else:
                lines[-1].append(word); L[-1] += len(word) + 1
        L.pop()
        ans = []
        for line, length in zip(lines, L):

            k = len(line)
            space = (maxWidth - length + k) // max(k - 1, 1)
            additional = maxWidth - length + k - space * max(k - 1, 1)
            if k == 1: s = line[0] + ' ' * space
            else:
                s = ''
                for i in range(additional):
                    s += line[i] + ' ' * (space + 1)
                for i in range(additional, k-1):
                    s += line[i] + ' ' * space
                s += line[-1]
            ans.append(s)
        s = ' '.join(lines[-1])
        ans.append( s + (maxWidth - len(s) ) * ' ' )
        return ans


print(Solution().fullJustify(words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16 ))
print(Solution().fullJustify(words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16))
print(Solution().fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],20))


