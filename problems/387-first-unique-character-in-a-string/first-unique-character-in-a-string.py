class Solution:
    def firstUniqChar(self, s: str) -> int:
        seen = {}
        for i, c in enumerate(s):
            if c in seen:
                seen[c] = -1
                continue
            else:
                seen[c] = i

        lowest = len(s)
        for key, val in seen.items():
            if val != -1:
                if val < lowest:
                    lowest = val
        if lowest == len(s):
            lowest = -1
        return lowest