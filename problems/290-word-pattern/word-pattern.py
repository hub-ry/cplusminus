class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        m = {}
        m1 = {}
        words = s.split()

        if len(pattern) != len(words):
            return False

        for c, w in zip(pattern, words):
            if c not in m:
                if w in m1:
                    return False
                m[c] = w
                m1[w] = c
            else:
                if m[c] != w:
                    return False
        return True